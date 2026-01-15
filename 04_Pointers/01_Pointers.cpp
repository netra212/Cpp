/**
 *
 * Pointers in C++.
 *
 */

//  This command is used to run the C++ file.
// clang++ 01_Pointers.cpp -o 01_Pointers && ./01_Pointers
// Data types depends on the RAM.
// int represent 4 bytes.
// 10 -> 1010
// Why the size of Pointer is constant ?

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    cout << &a << endl;
    cout << a;

    // Pointers Declaration.
    // data_type *var_name;
    int *ptr = &a;
    cout << ptr << endl;

    // float m = 2.6;
    // float &ptr1 = &m;
    // cout << ptr1 << endl;

    int a1 = 10;
    int *ptr1 = &a1;
    cout << "Printing the value of `a1` instead of `address` of `a1` using the derefencing operator: " << *ptr1 << endl;

    cout << sizeof(ptr1) << endl;
}
