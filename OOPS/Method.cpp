#include <iostream> 
using namespace std;

class myClass {
    public : 
    void myMethod() {
        cout << "Good Evening";
    }
};

int main() {
    myClass myObj;
    myObj.myMethod();
    return 0;
}
