// memory management in c++ 

// memory address management in c++
// when a variable created in c++,a memory is assigned to the variable, and when we assign a value to the variable its stored in the memory address. 


// var, let, const - 

#include <iostream> 
#include <string> 
using namespace std;

int main() {
    string food = "Pizza";

    cout << &food;
    return 0;
}
