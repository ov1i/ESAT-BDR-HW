#include <chrono>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-10

void readWrapper(double &a);
bool checkNumber(double &a);
void sqrtSubunitar(double &a);

int main() {
    double a;

    // Read a number "a"
    readWrapper(a);

    // Check if is between [0,1] and if so compute it's sqrt
    if(checkNumber(a)) { 

    }

    sqrtSubunitar(a);

    return 0;
}

void readWrapper(double &a) {
    printf("Please enter a real number: ");
    
    if(scanf("%lf", &a) != 1) {
        printf("Failed to read a real number!\n");
        exit(1);
    }
}

bool checkNumber(double &a) {
    if(a >= 0 && a <= 1) {
        return true; // Subunitar
    }
    return false;
}

void sqrtSubunitar(double &a) {
    double X1, X2, y;

    clock_t duration_ms = clock();
    const auto start{std::chrono::high_resolution_clock::now()};

    if (a == 0) {
        X2 = 0; /* radical din zero este zero*/
    } else {
        if (a == 1)
            X2 = 1; /* radical din 1 este 1 */
        else { /* “a” este diferit de 0 sau 1 */
            X2 = 1;
            do {
                X1 = X2;
                X2 = 0.5*(X1 + a / X1);
                if ((y = X1 - X2) < 0) 
                    y = -y; /* y = abs(X1-X2) */
            } while (y >= EPS);

        } /* else */    
    }
    const auto finish{std::chrono::high_resolution_clock::now()};
    duration_ms = clock() - duration_ms;

    const std::chrono::duration<double, std::nano> duration{finish - start};
    printf("\nsqrt(%g) = %g -> duration:%g (ns) | duration:%f (ms)\n", a, X2, duration, (duration_ms / CLOCKS_PER_SEC) * 1000);
}