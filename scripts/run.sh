clean_artifacts() {
    echo "Build cleanup started.."
    if [ -d ".build" ]; then
        sudo rm -rf .build
    fi
    if [ -d "logs" ]; then
        sudo rm -rf logs
    fi

    echo "Build cleanup finished.."
}

sync() {
    # Install minimal prerequisites (Ubuntu 18.04 as reference)
    sudo apt update && sudo apt install -y cmake g++
}

logger() {
    if [ $1 -eq 1 ]; then
        mkdir -p logs
        if [ $? -ne 0 ]; then
            echo "Failed to create logs. Exiting with code -1."
            exit -1
        fi
        LOG_FILE=logs/$( date '+%Y-%m-%d_%H-%M-%S' ).log

        # Redirect stdout and stderr, adding a timestamp to each log line
        exec > >(while IFS= read -r line; do echo "$(date '+%Y-%m-%d %H:%M:%S') $line"; done | tee $LOG_FILE) 2>&1
        if [ $? -ne 0 ]; then
            echo "Failed to redirect file descriptors. Exiting with code -1."
            exit -1
        fi
        echo -e "Logger set up & started"
    elif [ $1 -eq 0 ]; then
        exec &>/dev/tty
        if [ $? -ne 0 ]; then
            echo "Failed to restore file descriptors to their original state. Exiting with code -1."
            exit -1
        fi
    fi
}

gracefull_exit() {
    echo "Logs generated succesfully, exiting with code $1."
    logger 0
    sleep 1
    exit $1
}


menuWrapper() {
   if [ $# -eq 0 ]; then
        echo "Usage: $0 [option] ..."
        echo -e "OPTIONS:"
        echo -e "\t-sync:\t Init env"
        echo -e "\t-build:\t Build the code"
        echo -e "\t-buildtarget:\t Build specific target"
        echo -e "\t-test:\t Test specific target"
        echo -e "\t-clean:\t Clean build artifacts"
        exit -1
    fi

    if [ "$1" == "-build" ] || [ "$1" == "-b" ]; then
        logger 1
        cmake . -B.build -GNinja -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_BUILD_TYPE=debug
        ninja -j4 -C .build
        gracefull_exit 1
    elif [ "$1" == "-buildtarget" ] || [ "$1" == "-bt" ]; then
        logger 1
        if [ -z "$2" ] || [ -z "$3" ]; then
            echo "Invalid target! Please verify the specified target and try again!"
        else
            cmake . -D$2=1 -D$3=1 -B.build -GNinja -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_BUILD_TYPE=debug
            ninja -j4 -C .build
            rm ./.build/CMakeCache.txt 
        fi

        gracefull_exit 1
    elif [ "$1" == "-test" ] || [ "$1" == "-t" ]; then
        if [ -z "$2" ] || [ -z "$3" ]; then
            echo "Invalid target! Please verify the specified target and try again!"
        else
            ./.build/ESAT/$2/$2_$3
        fi
    elif [ "$1" == "-clean" ] || [ "$1" == "-c" ]; then
        logger 1
        clean_artifacts
        gracefull_exit 1
    elif [ "$1" == "-sync" ] || [ "$1" == "-s" ]; then
        logger 1
        sync
        gracefull_exit 1
    else
        echo "Error: Invalid argument"
        echo "Usage: $0 [option] ..."
        echo -e "OPTIONS:"
        echo -e "\t-sync:\t Init env"
        echo -e "\t-build:\t Build the code"
        echo -e "\t-buildtarget:\t Build specific target"
        echo -e "\t-test:\t Test specific target"
        echo -e "\t-clean:\t Clean build artifacts"

        exit -1
    fi
}

main() {
    menuWrapper $*
}

main $*
