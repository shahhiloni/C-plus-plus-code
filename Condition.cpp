#include <iostream>
using namespace std;
// condition

// int main() {
//     int marks;
//     cout<< "Enter Marks:";
//     cin >> marks;

//     if(marks >= 30){
//         cout << "grade A";
//     } else if (marks >=20){
//         cout << "grade B";
//     } else if(marks >= 10) {
//         cout << "grade c";
//     } else {
//         cout <<"fail";
//     }

//     return 0;
// }


// license (nested condition statement example)

int main(){
    int age;
    cout<<"enter your age:";
    cin >> age;

    if(age >=18){
        int license;
        cout<<"do you have a license? (1 = yes, 0=no) :";
        cin >> license;

        if(license == 1){
            cout<<"you can drive";
        } else {
            cout<< "you can't drive";
        } }
        else {
             cout<< "you are not eligible";
        }

    return 0;
}

// what is the difference between ==  and === 
// == : only match value
// === : match value and data Type