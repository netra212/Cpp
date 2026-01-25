#include <iostream>
using namespace std;

// Q. Tower of Hanoi.
void towerOfHanoi(int numDisk, int source, int help, int destination)
{
    /**
     * Condition.
     * 1. I can move only one disc at one time like only top disc.
     * 2. cannot place larger disc on the top of smaller disc.
     */
    if (numDisk == 1)
    {
        cout << "Move Disc " << numDisk << " from " << source << " to " << " destination" << endl;
    }
    towerOfHanoi(numDisk - 1, source, destination, help);
    cout << "Move Disc " << numDisk << " from " << source << " to " << " destination " << endl;
    towerOfHanoi(numDisk - 1, help, source, destination);
}

//
int main()
{
    //
}
