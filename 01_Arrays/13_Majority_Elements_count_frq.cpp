/***
 * This file is the part of the Lecture 35 of ther Coder Army youtube channels.
 * Topic Name: Majority Elements|| Count Frequency of element || Find Missing and Repeating elements.

 *
 *
 * NOTE: THIS LECTURE NEEDS TO BE RE-WATCHED.
 * I DID NOT UNDERSTAND THIS LECTURE PROPERLY IN ONE TIME.
 */
#include <iostream>
using namespace std;

// Q. How to store 2 Numbers in 1 Position.
void store2NumbersIn1Position()
{
    // N = 1 to 99.
    // store number and it's occurence.
    // 2, 2, 2, 2, 2, 2.
    // (2, Occurance)
    // Approach
    // Number = 602 % 100 = 2
    // Occurence = 602 / 100 = 6
}

// Q. Find Missing and Repeating.
vector<int> findMissingAndRepeating(vector<int> &array, int n)
{
    // [4, 3, 2, 1, 2, 7, 6], N = 7
    // Missing = 5
    // Repeating = 2
    /**
     * Approach:
     * sort the array or vector. Time Complexity: O(nlogn)
     * [1, 2, 2, 3, 4, 6, 7]
     * Missing = 3
     * Repeating = 2
     *
     * Hint: Nice methods.
     * Make a new array (count)
     * fill the count array with zeros initially.
     * count = [0, 0, 0, 0, 0, 0, 0, 0]
     * then check if how many times each element exist in original array and updated the count of particular element in the count array.
     * if count > 1 then repeated.
     * if count < 1 then missing.
     *
     * Approach: new
     * [4, 3, 2, 1, 2, 7, 6]
     * Decrease every element by 1.
     * then mark as count.
     * if any element becomes zero
     *
     * vector<int> count(N, 0);
     * for(int i = 0; i < N; i++){
            count[arr[i]-1]++;
     * }
    //  then finding the missing.
    for(int i = 0; i < N; i++){
        if(count[i] == 0){
            cout << i+1;
            break;
        }
    }

    // then finding the repeating number.
    for(int i = 0; i < N; i++){
        if(count[i] == 2){
            cout << i+1;
            break;
        }
    }
    Time Complexity: O(N)
    Space Complexity: O(N)

    // More Optimized Way to solve this...
    No extra space.
    substract every element of array with 1.
    [4, 3, 2, 1, 2, 7, 6]
    Like this
    [3, 2, 1, 0, 1, 7, 6]
    then
    // Code....
    // Time Complexity: O(N)
    // Space Complexity: O(N)
     */

    //  Decrease value by 1.
    for (int i = 0; i < n; i++)
    {
        array[i]--;
    }

    // Occurannce of number.
    for (int i = 0; i < n; i++)
    {
        array[array[i] % n] += n;
    }

    vector<int> ans(2);

    // for the repeating and missing number.
    for (int i = 0; i < n; i++)
    {
        if (array[i] / n == 2) // repeating number.
        {
            ans[0] = i + 1;
        }
        else if (array[i] / n == 0) // missing number case.
        {
            ans[1] = i + 1;
        }
    }

    return ans;
}

// Q. Finding the Occurrence of Numbers in the arrays.
vector<int> findOccurrenceOfNumbers(vector<int> &arr, int n)
{
    // [3, 2, 5, 3, 1, 2, 3, 7]
    /**
     * arr = [3, 2, 5, 3, 1, 2, 3, 7]
     *
     */
}

// Q. Find the majority element.
// when majorityElement > N/2.
// suppose, n = 11, n/2 = 5.
// we need to find such number whose count is more than 5.
// The majority element is the element that appears more than n/2 times.
int findMajorityElementGreaterThanNDivide2(vector<int> &arr, int n)
{
    // [3, 3, 2, 3, 1, 3, 2, 2, 1, 3, 3], N = 11
    // Approach: cancel the candidate and their count.
    // Implements the `Moore Voting Algorithm`.
    int candidate, count = 0;

    // Moore Voting Algorithm.
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count += 1;
            candidate = arr[i];
        }
        else
        {
            if (candidate == arr[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
    }
    return candidate;
}

// main functions.
int main()
{
    //
}
