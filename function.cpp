// Function : a function is a block of code which only run when its called 

// here we pass data, known as parameter , into a function
// function perform actions, important code, reuseable code, 
// declare ort define once and use multiple times. 

// myFunction(id, name) {

// }
    
// {

// }

// - Normal Function 
// - function parameters
// - Function overloading 
// - scope (local scope, global Scope)
// - Recursion Function 
// - Lambda Function

// Normal Function 
// #include <iostream>
// using namespace std; 

// void myFunction() {
//     cout<< "Hello, Good Afternoon"; 
// }


// int main(){
//     myFunction();
//     return 0;
// }


// parameters and Arguments 
// parameters  : information can be passed to function as a parameter. 
// - parameters act as variable inside the function 

// variable 

// - var, let, const
// 1. var : can support re-declare and re-assign 

// 2. let : its only support re-assign 

// 3. const : can't support re-declare, and re-assign 

// // var hello 

// // var hello 

// ex:  
// void Good (name1, name2, name3) {

// }

// parameters and arguments 
// #include <iostream>
// #include <string> 
// using namespace std;

// void Hey(string fname) {
// cout << fname << "Hello" << endl;
// }

// int main() {
//    Hey("Good Morning");
//    Hey("Good afternoon");
//    Hey("Good evening");
//    return 0;

// }

// Function Overloading
// - function overloading allow or support multiple functions to have the same name, as long as their parameters are different dataType or numerics


// Function Overlaoding Code 
// #include <iostream> 
// using namespace std;


// int Hello (int x, int y) {
//     return x + y;
// }

// double Good (double x, double y){
//     return x + y;
// }


// int main() {
//     int my1 = Hello(4, 5);
//     double my2 = Good(3.9090, 4.909);
//     cout << "Int : " << my1 << endl;
//     cout << "Double : " << my2;
//     return 0;
// }


// 5! = 5*4*3*2*1 = 
// 10 = 1+2+3+4+5+6+7+8+9+10 = 55

// recursion function 
// - recursion is keyword
// - recursion is a techniqies of making a function call itself 
// - use for solve complicated function or a programs and this function helps to solve complexity of a function its called recursion 

// recursion function 
// i, j, k - its use for store value, finding value and represent value in a mathmetical way 



#include <iostream>
using namespace std;

int sum(int k) {
    if(k > 0) {
        return k + sum (k-1);
    } else {
        return 0;
    }
}

int main () {
    int result = sum (10);
    cout << result ;
    return 0;
}



