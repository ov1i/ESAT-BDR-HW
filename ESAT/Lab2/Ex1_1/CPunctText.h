/* Copy constructor */
//CPunctText.h
#include <cmath>
constexpr int dim_sir = 21;//+1 for \0
class CPunctText {
    int x;
    int y;
    // int lungime_sir;//redundant
    char *sNume;
public:
    //explicit empty constructor
    CPunctText( );
    //parameterized constructor, last parameter with implicit value
    CPunctText(int ix, int iy, const char *sText = "Punct");
    //copy constructor
    CPunctText(const CPunctText &pct);

    /// @brief Move constructor
    /// @param obj Object to be moved
    CPunctText(CPunctText&& obj) noexcept;  

    //destructor
    ~CPunctText( );

    // void afis() {
    //     cout << "Object has x= " << x << endl;
    //     cout << "Object has y= " << y << endl;
    //     cout << "Object has the array of characters = " << sNume << endl;
    // }//afis

    /// @brief Getter for X member
    /// @return x
    int getX() {
        return x;
    }

    /// @brief Getter for Y member
    /// @return y
    int getY() {
        return y;
    }

    /// @brief Getter for name length
    /// @return Returns length of the name
    size_t getLength() {
        return strlen(sNume);
    }

    /// @brief Getter for sNume member
    /// @return sNume (pointer to the name)
    char* getName() {
        return sNume;
    }

    /// @brief Computes the distance from a point to the origin
    /// @return Returns the distance (double)
    double computeDistance() {
        return sqrt(pow(static_cast<double>(x) - 0.0, 2.0) + pow(static_cast<double>(y)- 0.0, 2));
    }


    // STATIC METHODS

    /// @brief Static Method for adding to different Points
    /// @param P1 - Point 1
    /// @param P2 - Point 2
    /// @return Returns the new point resulted from the addition
    static CPunctText addPoints(CPunctText &P1, CPunctText &P2) {
        int totalLength = P1.getLength() + P2.getLength() + 1;
        int x = P1.getX() + P2.getX();
        int y = P1.getY() + P2.getY();

        char* name = (char*)malloc(totalLength * sizeof(char)); 
        strcpy(name, P1.getName()); 
        strcat(name, P2.getName());

        CPunctText P3(x,y,name);

        return P3;
    }
};//class

CPunctText::CPunctText() {
    cout << "----Empty explicit constructor----\n";
    x=y=0;
    // lungime_sir = dim_sir;
    sNume = new (nothrow) char[dim_sir];
    strcpy(sNume, "Unknown");
}

CPunctText::CPunctText(int ix, int iy, const char *sText) {
    cout << "----Parameterized constructor----\n";
    // lungime_sir = strlen(sText) + 1;// pentru \0
    sNume = new (nothrow) char[strlen(sText) + 1];
    x = ix;
    y = iy;
    strcpy(sNume, sText);
}

CPunctText::CPunctText(const CPunctText &pct) {
    cout << "----Copy constructor----\n";
    sNume = new (nothrow) char[strlen(pct.sNume)];
    x = pct.x;
    y = pct.y;
    // lungime_sir = pct.lungime_sir;
    strcpy(sNume, pct.sNume);
}

CPunctText::CPunctText(CPunctText&& obj) noexcept { // Move constructor, no copy created
    cout << "----Move constructor----\n";
    this->x = obj.x;
    this->y = obj.y;
    size_t len = strlen(obj.sNume) + 1;

    this->sNume = (char*)malloc(sizeof(char) * len);

    strcpy(this->sNume, obj.sNume);

    if(obj.sNume)
        delete[] obj.sNume;

    obj.sNume = nullptr;
}

CPunctText::~CPunctText() {
    cout << "----Destructor----\n";
    if(sNume) 
        delete[] sNume;
}
