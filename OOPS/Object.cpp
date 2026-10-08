// Object : In C++ an object is created from a class.we already created the class named myClass, so noe we can use this to create a objects. 

#include <iostream>
#include <string> 
using namespace std;

class MyClass {
    public :  
    int myNumber;
    string myString;
};

int main() {
    MyClass myObj;
    myObj.myNumber = 10;
    myObj.myString = "Hello, Good Evening";

    cout << myObj.myNumber << endl;
    cout << myObj.myString;
    return 0;

}
