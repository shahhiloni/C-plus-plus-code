*** Variables in C++

- A variable is like a labled container in memory, used to stored data that program can be used
- LOWERCASE(a-z), uppercase (A-Z)
- no space and Special Character allowed in C++ (@, #, $, %)
%hello - not allowed in C++
- C++ is case - sensitive (95 keywords)

10 
a = 20;

*** Data - types in C++ 
1. primitive data types 
- int, float, double, boolean
int - 4 bytes (1 byte = 8 bits) - 32 bit
- memory store in binary (0, 1)

1. int (4 bytes) (0-255)
2. float(4 bytes) 89.909090909 (7) (0 -255)
3. double (8 bytes) 90.0000000999988888 (15)
4. boolean (0, 1) - 
0 - false 
1 - true 
5. char ( 1 bytes) - "A", "b" 

2. non - primitive data types
- array : store same data- typpe 
array[5] = {3, 4, 5, 7, 6}

- structure 
- pointer (memory storage)
- enum 
- union

## constant : 
a = 10; 
a = 20;

const a = 10;
a = 20;

- in Constant we can't change the value once assigned

pie = 3.14
mathmatical function, gaming software development, theorem

## operators 
1. arithmetic operator : (+, -, %, *, /, ++, --)
2. Relational Operators : (=, ==, !=, <, >, <=, >=)

3. logical Operators : (&&, ||) - output in string
AND Gate

 0 1 = 0
 1 0 = 0
 1 1 = 1
 0 0 = 0

OR Gate

0 1 = 1
1 1 = 1
1 0 = 1
0 0 = 0

NOT : 
0 0 = 0 (1) - true
( 0 = 1, 1 = 0)

XOR : 
0 0 = 0 
0 1 = 1
1 1 = 0 
1 0 = 1

(same value = 0, different value = 1)

4. Assignment Operators 
(=, +=, -=)

a = 10;

a += 10;
a = 11;

a -= 10;
a = 9;

5. Bitwise Operators : output in Boolean (bits)
(&, |, )
AND gate  
0 1 = 0
1 1 = 1

OR gate
XOR gate
NOT gate

6. Conditional Operators 
- if else 

condition 
{18 + ? yes : No} - ternary operator 

7. Special Operator : memory, size, object, pointers


## scopes
1. local scope 
2. global scope
- value gives in bracklets o block 
{

}

## condition
- condition used for making decision and output 
- if and  else 
- depends statement 

- > termary operator (is a short form of if else condition)
(num ? yes : No)

? - if
: - else 