#include <iostream>
using namespace std;

// Q. Longest substring without repeating characters.
int LongestSubstringWithoutRepeatingChar(string &str)
{
    /**
     * Example 1:
     * abcdecbeadf
     *
     * Approach:
     * temp = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
     * Check either the given character of string is present in the temp vector of string types or not...
     * if present in tempVector then increase the count by 1 for that particular character.
     *
     * # Sliding Window Approach.
     *
     * 1.Create a window using two pointers:
            left → start of the window
            right → end of the window
        2. Move the right pointer to expand the window
        3. Move the left pointer to shrink the window when needed
        4. Update the result while sliding
     */
    vector<bool> count(256, 0); // total character is 256.
    int first = 0, second = 0, len = 0;
    // second will go up to last so .
    while (second < str.size())
    {
        // when the count of c or any character is equal to 1 then make the count of first equal to zero.
        // if repeating character is seen then stop and make that repeating character zero. and move first.
        while (count[str[second]]) // removing the repeating characters.
        {
            count[str[first]] == 0;
            first++;
        }
        // now, making an second character 1.
        count[str[second]] == 1;

        // Now, update the length by substracting second - first + 1 since indexing start with zero.
        len = max(len, second - first + 1);
        second++;
    }
    return len;
}

// Q. Finding the smallest substring where all the characters must be present at least one time.
// NOTE: NEED TO DRY RUN IN COPY.
int smallestDistinctWindow(string &str)
{
    /**
     * Example: AABBBCBBAC
     * NOTE: when all the characters comes, then we decrease the size of the window by increasing first from left to right til second.
     * Approach:
     * first let say shortest lenght is
     * len = 10
     * So, let say count array which keeps the track of the how many times each variables appears in the given string.
     * count = [0,0,0,0,0,0,0,0......0]
     * Run the loop,
     * then check if 'a' is appears
     * if not then increase the count by 1 in count array.
     * then decrease the differenceVariable's value by 1 for that particular character.
     * Now update the length.
     * then decrease the size of the window.
     */
    vector<int> count(256, 0);
    int first = 0, second = 0, len = str.size(), diff;

    // Calculate all the unique characters.
    // Approach, we need to count all the different unique substring, then we have to return the smallest substring out of that.

    // so need to traverse whole string.

    while (first < str.size())
    {
        // if count of str[anyChar] = 0 on countVector, then we can assume that, this particular character is equal to zero.
        if (count[str[first]] == 0)
        {
            diff++; // since, first character is unique, so, diff increase.

            count[str[first]]++; // Increasing the count of that particular character in countVector so that next loop we can know that this character is already counted.
            first++;
        }
    }
    // since, we already know the count of each character or stored the count of each character in the above count vector so that we have to clear the count for the next operations.
    for (int i = 0; i < 256; i++)
    {
        count[i] = 0; // count vector becomes zero.
        first = 0;    // firstPointer comes at first Position.
    }

    // secondPointer or index travels till every unique characters aaudina.
    // second wala index teti bela samma increase huncha jati bela samma,sabaii unique character maro window ma aaudaina...
    while (second < str.size())
    {
        // till the diff exist or diff becomes zero.
        while (diff && second < str.size())
        {
            // yasko matlab unique character cha count ma so that diff ko value laii decrease gareko.
            if (count[str[second]] == 0)
            {
                diff--;
            }
            // decrease window value till diff ko value one hudaina.
            count[str[second]]++;
            second++;
        }
        len = min(len, second - first);

        while (diff != 1)
        {
            // now, decrease the size of the window.
            len = min(len, second - first);
            count[str[first]]--;

            if (count[str[first] == 0])
            {
                diff++;

                first++;
            }
        }
    }

    return len;
}

//
int main()
{

    //
}