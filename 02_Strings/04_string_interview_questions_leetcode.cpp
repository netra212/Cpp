/**
 *
 *
 */

#include <iostream>
using namespace std;

// Q. Soot Vowel in a string.
string sortVowelInAString(string &str)
{
    // str = leetcode
    /**
     * sort an string in an increasing order of ASCII values.
     * In this questions, It is ask to sort an vowel in Increasing order of ASCII values.
     * Vowels in the above string: eeoe
     * means we have to sort this characters: `eeoe' in increasing order of their ASCII values.
     * finalAns = 'leetcedo';
     *
     * Approach:
     * 1. select the vowels.
     * 2. sort the vowels.
     * 3. Insert the vowels at their right position.
     *
     */
    vector<int> lowerCaseCount(26, 0);
    vector<int> upperCaseCount(26, 0);

    // Running loop over the original arrays.
    for (int i = 0; i < str.size(); i++)
    {
        // Lower case, vowels = a, e, i, o, u.
        // Lower Case ma, lower vowels ko count store garna parcha.
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            // if i = b;
            // means 98 - 'a' => 98 - 97 => 1
            // It means In lowerCaseCount vector it will goes to 1 index position then increase count of lowerCaseCount of b by one.
            int index = str[i] - 'a';
            lowerCaseCount[index]++;
            str[i] = '#'; // making an # to that particular vowel character as #.
        }
        else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            // same applies to this as well.
            upperCaseCount[str[i] - 'a']++;
            str[i] = '#'; // making an # to that particular upper character as #.
        }
    }

    //
    string vowel;

    // for upper.
    for (int i = 0; i < 26; i++)
    {
        char c = 'A' + i;
        while (upperCaseCount[i])
        {
            vowel += c;
            upperCaseCount[i]--;
        }
    }

    // for lower.
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        while (lowerCaseCount[i])
        {
            vowel += c;
            lowerCaseCount[i]--;
        }
    }

    int first = 0, second = 0;
    // first pointing to the original str.
    // second pointing to the vowels string.
    while (second < vowel.size())
    {
        if (str[first] == '#')
        {
            // Updating the first string vector with vowel.
            str[first] = vowel[second];
            second++;
        }
        first++;
    }

    return str;
}

// Q. Add string.
void addString(string &str1, string &str2)
{
    //
}

int main()
{

    //
}

//