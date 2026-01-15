/**
 * KMP Algorithm.
 *
 */

#include <iostream>
using namespace std;
/**
 *
 */
// Q. Longest Prefix suffix.
int LongestPrefixSuffix(string &str)
{
    /**
     * Find the longest prefix and suffix from the given example.
     * Here is the catch, we cannot take all the string.
     * Example: ABCDEAABCD
     * Prefix:
     */

    vector<int> lps(str.size(), 0);
    int pre = 0, suf = 1;
    while (suf < str.size())
    {
        // if prefix matched with suffix.
        if (str[pre] == str[suf])
        {
            lps[suf] = pre + 1;
            suf++, pre++;
        }
        else
        {
            // if prefix and suffix do not matched.
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
    return lps[str.size() - 1];
}

//
int main()
{
    //
}
