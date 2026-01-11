/**
 * solving an string interview questions.
 */
#include <iostream>
using namespace std;

// Q. Defanging an IP address.
string defangingAnIPAddress(string address)
{
    /**
     * Example 1:
     * address = 1.1.1.1
     * ans = 1 [.] 1 [.] 1 [.] 1
     * address = 255.100.25.60
     * ans = 255 [.] 100 [.] 25 [.] 60
     * while loop
     * if address[i] == '.'
     * ans = swap('.', '[.]'); or ans = ans = '[.]'
     * else
     * ans = ans + s[index];
     * index++;
     * return ans;
     */
    int index = 0;
    string ans;
    while (index < address.size())
    {
        if (address[index] == '.')
        {
            ans = ans + "[.]";
        }
        else
        {
            ans = ans + address[index];
        }
        index++;
    }
    return ans;
}

// clockwise rotating of an string.
void rotateClockwise(string &clockwise)
{
    // string s = 'amazon';
    // [ a | m | a | z | o | n ]
    char c = clockwise[clockwise.size() - 1];
    int index = clockwise.size() - 2;
    while (index >= 0)
    {
        clockwise[index + 1] = clockwise[index];
        index--;
    }
    clockwise[0] = c;
}

// anticlockwise rotating of an string.
void rotateAnticlockwise(string &anticlockwise)
{
    char c = anticlockwise[0];
    int index = 1;
    while (index < anticlockwise.size())
    {
        anticlockwise[index - 1] = anticlockwise[index];
        index++;
    }
    anticlockwise[anticlockwise.size() - 1] = c;
}

// Q. Check if string is rotated by 2 places.
bool checkIfStringRotatedBy2Places(string &str1, string &str2)
{
    if (str1.size() != str2.size())
    {
        return 0;
    }
    string clockwise, anticlockwise;
    clockwise = str1;
    rotateClockwise(clockwise);
    rotateClockwise(clockwise);

    if (clockwise == str2)
    {
        return 1;
    }

    anticlockwise = str1;
    rotateAnticlockwise(anticlockwise);
    rotateAnticlockwise(anticlockwise);

    if (anticlockwise == str2)
    {
        return 1;
    }
    return 0;
}

// Q. check pangram.
int checkPangram(string &str)
{
    /**
     * sentence = 'the quick brown fox jumps over the lazy dog'
     * Is all the alphabets of lower case present in the above sentence, this is called pangrams.
     * Approach:
     * int index = 0;
     * while(index <= str.size())
     * if(str[index] == 'a'){

     * }
     */
    vector<bool> alphabet(26, 0);
    for (int i = 0; i < str.size(); i++)
    {
        // finding the index of i.
        int index = str[i] - 'a';
        // making an 1.
        alphabet[index] = 1;
    }

    // printing.
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Q. sort an string.
void sortAnString(string &str)
{
    /**
     * Approach:
     * make a new vector of string type.
     * we need to find the index of every alphaet along with their own count.
     */
    vector<int> alphabet(26, 0);
    for (int i = 0; i < str.size(); i++)
    {
        alphabet[str[i] - 'a']++;
    }

    string ans;
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        while (alphabet[i])
        {
            ans += c;
            alphabet[i]--;
        }
    }
}

//
int main()
{
    string s = "amazon";
    rotateClockwise(s);
}