/***
 *
 */
#include <iostream>
using namespace std;

// Q. string matching.
int stringMatching(string &haystack, string &needle)
{
    /**
     * Example: `abcdefghikl` --> can be denoted at hasystack.
     * string to be search: `def` --> can be denoted at needle.
     *
     */
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i < n - m; i++)
    {
        int first = i, second = 0;
        while (second < m)
        {
            if (haystack[first] != needle[second])
            {
                break;
            }
            else
            {
                first++, second++;
            }
        }
        if (second == m)
        {
            return first - second;
        }
    }
    return -1
}

//
int main()
{
    //
}