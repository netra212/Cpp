#include <iostream>
using namespace std;

// Q. Predict the winner.
int predictTheWinner(vector<bool> &person, int n, int index, int personLeft, int k)
{
    // Base case handling.
    if (personLeft == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (person[i] == 0)
            {
                return i;
            }
        }
    }

    /**
     * Intuition to solve this Problem.
     * 1. kill the person.
     * 2. Find the next alive person.
     */

    // If the value of k is large then we have to loop around the same arrays that's why.
    // Find the position of kill.
    int kill = (k - 1) % personLeft;

    while (kill--)
    {
        index = (index + 1) % n;
        // skip the person who is already killed.
        while (person[index] == 1)
        {
            index = (index + 1) % n; // skipping the eliminated person.
        }
    }
    person[index] = 1;

    // Finding the next alive person.
    while (person[index] == 1)
    {
        index = (index + 1) % n;
    }

    return predictTheWinner(person, n, index, personLeft - 1, k);
}

//
int main()
{
    vector<bool> person;
}