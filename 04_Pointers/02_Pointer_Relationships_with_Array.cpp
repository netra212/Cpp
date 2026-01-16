#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {11, 7, 8, 12, 14};
    int *ptr = arr;

    int *ptr1 = &arr[0];
    int *ptr2 = &arr[1];
    int *ptr3 = &arr[2];
    int *ptr4 = &arr[3];
    int *ptr5 = &arr[4];

    // How can i get the address of the particular elements.
    // ith_index_address = base_address + i *size_of_Datatype.

    // Print the address of first element.
    cout << ptr << endl;

    // Print the address of all the elements.
    for (int i = 0; i < 5; i++)
    {
        cout << arr + i << endl;
    }

    // Print all the values.
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr + i) << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << *ptr << endl;
        ptr++;
    }
    return 0;
}
