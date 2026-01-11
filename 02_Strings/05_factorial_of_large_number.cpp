/**
 *
 */
#include <iostream>
using namespace std;

int num(char c)
{
    if (c == 'I')
    {
        return 1;
    }
    else if (c == 'V')
    {
        return 5;
    }
    else if (c == 'X')
    {
        return 10;
    }
    else if (c == 'L')
    {
        return 50;
    }
    else if (c == 'C')
    {
        return 100;
    }
    else if (c == 'D')
    {
        return 500;
    }
    else
    {
        return 1000;
    }
}

// Q. Roman Numbers to Integers.
int RomanNumbersToIntegers(string &str)
{
    /**
     * I -> 1,II -> 2,III -> 3,IV -> 4, V -> 5, VI -> 6, VII -> 7, VIII -> 8, IX -> 9, X -> 10, XI -> 11, XII -> 12, XIII -> 13, XIV -> 14, XV -> 15, XVI -> 16, XVII -> 17, XVIII -> 18, XIX -> 19, XX -> 20
     * Simple technique:
     * if any large character appears next to previous character then consider the smallest character as negative like this.
     * Example: CD Where C denotes 100, and D denotes 500
     * CD -> -100 + 500
     * Similarly, MCCXLVIII
     * M -> 1000, C -> 100, X -> 10, L -> 50, V -> 5, I -> 1.
     * so,
     * MCCXLVIII -> 1000 + 100 + 100 + 10 + 50 + 5 + 1 + 1 + 1
     *
     * Code.
     * int num(char c){
            if(c == "I"){
                return 1;
            } else if(C == "V"){
                return 5;
            } else if(C == "X"){
                return 10;
            } else if(C == "L"){
                return 50;
            } else if(C == "C"){
                return 100;
            }else if(C == 'D'){
                return 500;
            }
            else{
                return ...
            }
     * }
     * string str
     * int sum = 0, index = 0;
     * while(index < str.size() - 1){
            if(num[str[index]] < num[str[index+1]]){
                sum -= num(str[index]);l
            }
            else{
                sum += num(str[index]);
            }
        index++
     * }
     * sum += num(str[str.size()-1])
     * return sum
     *
     */
    int sum = 0, index = 0;
    while (index < str.size() - 1)
    {
        if (num(str[index]) < num(str[index + 1]))
        {
            sum -= num(str[index]);
        }
        else
        {
            sum += num(str[index]);
        }
        index++;
    }

    sum += num(str[index]);
    return sum;
}

// Q. Converting the integers numbers to Roman numbers.
void integersToRomanNumbers(string &str)
{
    /**
     * Example: 1248, -> 1000 + 200 + 40 + 8
     * 1000 -> M
     * 200  -> CC
     * 40   -> XL
     * 8    -> VIII
     */
    // NOTE: HOMEWORK.
}

// Q. Calculate the factorial of a numbers.
void factorialOfANumbers(int N)
{
    vector<int> ans(1, 1); // vector automatically increase it size.
    while (N > 1)
    {
        int carry = 0, result, size = ans.size();
        for (int i = 0; i < size; i++)
        {
            result = ans[i] * N + carry;
            carry = result / 10; // carry for the next one.
            ans[i] = result % 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
        N--;
    }
}

//
int main()
{
    //
}
