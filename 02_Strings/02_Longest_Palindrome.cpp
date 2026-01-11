/**
 *
 * This file is the part of the Lecture 38: of Coder Army.
 *
 */
#include <iostream>
using namespace std;

// Q1. Longest Palindrome.
int findLongestPalindrome(string s)
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

    // frequency updated.
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
    bool odd = 0;

    //
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
            count += lowerCharCount[i] - 1;
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
            count += upperCharCount[i] - 1;
            odd = 1;
        }
    }
    int longestPalindromeAns = count + odd;
    return longestPalindromeAns;
}

// Q. sorting the sentences.
string sortingTSentences()
{
    /**
     * s = "is2 sentence4 This1 a3"
     * s = "Myself2 ME1 I4 and3"
     * NOTE: Last Position of each word shows the index of that particular word.
     * Loop over the particular string s, then fetch the first word, store word that word into a another temporary vector with string type... Like this.....!
     * temp = 'Myself2'
     * Now, we need to access the last character of the that word, which shows the index of that word.

     * so, PositionOfParticularWord = temp[temp.size()-1]; // Accessing last character.
     * so, we need to convert that 'PosWord' into an int.
     *
    // Accessing the character like this..
    ParticularWord = temp.pop_back(); // remove the last character.
     *
     */

    string s;
    vector<string> ans(10);
    string temp;
    // count store the total number of words in the given string.
    int count = 0, index = 0;
    while (index < s.size())
    {
        if (s[index] == ' ')
        {
            // Accessing the index of that particular word.
            int Pos = temp[temp.size() - 1] - '0'; // - '0' <-- indicates the converting from string into int type.
            temp.pop_back();                       // removing last digit like 2.
            temp.clear();
            count++;
        }
        else
        {
            temp += s[index];
            index++;
        }
    }

    // Printing the ans vector.
    for (int i = 1; i <= count; i++)
    {
        temp += ans[i];
        temp += ' ';
    }
    temp.pop_back(); // removing the last space. because when we add the last character along with space... like this..
    // 'myself netra khatri Ok '
    // As we can seen in the above string, there is space in the last place so.
    return temp;
}

//
int main()
{
    //
}