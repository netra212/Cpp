#include <iostream>
using namespace std;

// N Bit binary numbers.
// Find all N Bit Binary Numbers having more than equal to 1 than 0 for any prefix.
int printNBitBinaryNumbers(int N, vector<string> &ans, string &temp, int zero, int one)
{
    /**
     * Let's suppose N = 4,
     * 1 1 0 1
     * Prefix ares:
     * 1
     * 1 1
     * 1 1 0
     * 1 1 0 1
     * Above are the whole problem scenarios.
     */
    if (temp.size() == N)
    {
        ans.push_back(temp);
        return;
    }

    // Adding ones.
    temp.push_back('1');
    printNBitBinaryNumbers(N, ans, temp, zero, one + 1);
    temp.pop_back();

    // Adding zeros.
    if (zero < one)
    {
        temp.push_back('0');
        printNBitBinaryNumbers(N, ans, temp, zero + 1, one);
        temp.pop_back();
    }
}

//
int main()
{
    //
}