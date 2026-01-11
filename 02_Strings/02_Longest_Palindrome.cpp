/**
 *
 * This file is the part of the Lecture 38: of Coder Army.
 *
 */
#include <iostream>
using namespace std;

// Q1. Longest Palindrome.
void findLongestPalindrome(string s)
{
    /**
     * aabbcbada
     * approach:
     * Count of each character.
     * a = 4, even number of times. so I can take all. `aaaa`.even laii direct add garne...
     * b = 3,  Odd number of times, can takes only two b. means 3-1 => 2 -> bb., Odd laii minus 1 garerww add garne.
     * c = 1, similary, since odd, so 1-1 => 0.
     * d = 2, even so take 2. dd.
     *
     * Palindrome: aabd       dbaa
     *
     * Another example:
     * aaaabb
     * a = 4
     * b = 2
     * here is palindrome, aabbaa
     *
     * Another example:
     * aAAbbA
     * a = 1 -> 1-1 => 0
     * A = 3 -> 3-1 => 2
     * b = 2 -> 2 => 2
     *             total => 4
     * And total odd number character => 1
     * so longest palindrome string is: 1 + 4 => 5
     *
     */
    string s;
    vector<int> lowerCharCount(26, 0);
    vector<int> upperCharCount(26, 0);

    // Loop over the lower character.
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a')
        {
            lowerCharCount[s[i] - 'a']++;
        }
        else
        {
            upperCharCount[s[i] - 'A']++;
        }
    }

    int count = 0;
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        // Even Case in Lower Character.
        if (lowerCharCount[i] % 2 == 0)
        {
            count += lowerCharCount[i];
        }
        // Odd case in Lower character.
        else
        {
            count += lowerCharCount[i];
            odd = 1;
        }

        // Even Case in Upper Character.
        if (lowerCharCount[i] % 2 == 0)
        {
            count += upperCharCount[i];
        }
        // Odd case in Upper character.
        else
        {
            count += upperCharCount[i];
            odd = 1;
        }
    }
}

//
int main()
{
    //
}