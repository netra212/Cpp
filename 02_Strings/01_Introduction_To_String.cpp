/**
 * Introduction to strings.
 * In string, memory allocated in Dynamically.
 * string stored in heap.
 * NOTE: string always have a null character at the end of string.
 */
#include <iostream>
using namespace std;

// Q. Reverse an string.
void reverseString(string s)
{
    //
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        swap(s[start], s[end]);
        start++, end--;
    }
    cout << s;
}

//
int main()
{
    string s = "Netra kc";
    // s.push_back('p');
    // s.pop_back();
}
