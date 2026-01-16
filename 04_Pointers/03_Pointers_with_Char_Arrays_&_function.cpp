/**
 * Pointers with Char Arrays and functions.
 */

#include <iostream>
using namespace std;

void increment(int *ptr)
{
    *ptr = *ptr + 1;
}

void makeDouble(int *p)
{
    for (int i = 0; i < 5; i++)
    {
        p[i] = 2 * p[i];
    }
}

void swapping(int *p1, int *p2) // Pass by Pointer.
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    cout << &p1 << endl;
    cout << &p2 << endl;
    cout << p1 << " " << endl;
}

//
int main()
{
    int num1 = 10;
    int &temp = num1;
    //

    int arr1[5] = {1, 2, 3, 4, 5};
    makeDouble(arr1);
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i];
    }

    // swapping two numbers.
    int first = 0;
    int second = 0;
    swapping(&first, &second);
    cout << first << second << endl;

    char arr[5] = {'1', '2', '3', '4', '\n'};
    char *ptr = arr;

    cout << static_cast<void *>(arr) << endl; // Print the values.

    cout << ptr << endl; // Print the values.
    cout << (void *)arr; // It will print the address, changing the character type of pointer to void type of the pointer.
    cout << (void *)ptr; // It will also print the address, because we are doing the type casting here.

    // What is void pointer ?
    // Indicate the location, but does not specify which types of data is that .....!

    char name = 'a';
    char *ptr1 = &name;
    cout << (void *)&name << endl;
    cout << (void *)ptr1 << endl;

    return 0;
}
