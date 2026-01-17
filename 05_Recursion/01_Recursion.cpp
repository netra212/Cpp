/**
 * Recursion in Depth.
 * A function which call itself again and again until specific conditions met.
 */

void greetHappyBirthDay(int n)
{
    return greetHappyBirthDay(n - 1);
}

#include <iostream>
using namespace std;

int main()
{
    int n = 3;
    greetHappyBirthDay(n);
    cout << "Happy Birthday...!" << endl;
}
