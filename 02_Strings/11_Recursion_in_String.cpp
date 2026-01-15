/**
 * Recursion in String.
 */
#include <iostream>
using namespace std;

// Q. Check either the string is palindrome or not
bool checkPalindrome(string &str, int start, int end)
{
    // Checking Base case.
    if (start >= end)
    {
        return 1;
    }

    //
    if (str[start] != str[end])
    {
        return 0; // Not Palindrome.
    }
    else
    {
        checkPalindrome(str, start + 1, end - 1);
    }
    return 1;
}

// Q. Count the number of vowels.
int countVowels(string &str, int index)
{
    int count = 0;
    // a, e, i, o, u.
    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')
    {
        return 1 + countVowels(str, index - 1);
    }
    else
    {
        countVowels(str, index - 1);
    }
}

//
int main()
{
    //
}