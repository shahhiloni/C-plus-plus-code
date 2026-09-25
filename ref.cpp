// reference in c++

#include <iostream> 
#include <string>
using namespace std;


int main () {
    string food = "Burger";
    string meal = food;

    // food = burger , meal = food 
    

    meal = "Pizza";

    cout << food << endl;
    cout << meal << endl;
    return 0;
}