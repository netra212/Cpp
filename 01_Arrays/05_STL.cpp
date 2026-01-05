/**
 * stl: Standard Template Library.
 * for vector, memory always allocated in heap.
 * heap: static memory allocation:
 * - compile time ma tha hoss kii code run garda kati memory chahincha vanerw.
 * stack: Dynamic memory allocation:
 * - runtime ma tha hoss kii code run garda kati memory chahicha vanerwww, user decided.
 *
 * Q. Why vector double size every time ?
 * - To maintain the time complexity in O(n).
 */

#include <iostream>
using namespace std;

// main function.
int main()
{
    // Vector Declaration.
    vector<int> v1(4);
    vector<int> v2 = {2, 4, 6, 8, 10};

    // How to insert an value in vector.
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(8);
    v1.push_back(12);

    // printing the vector.
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i];
    }

    // How to remove value from vector.
    v1.pop_back(); // O(1)
    v1.clear();
    v1.erase(v1.begin() + 2); // O(n)

    // Size and Capacity.
    // size = total number of elements present in the vector.
    // capacity = total number of element that can be fit into the vector.

    // Front, back, at, empty.
    cout << v1.front(); // gives output of front element.
    cout << v1.back();  // gives output of last element.
    cout << v1.empty(); // check either vector is empty or not.

    // Iterator in a Vector.
    v1.begin();
    v1.end();

    //
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        //
        cout << *it << " ";
    }

    //
    v1.rbegin(); // reverse begining.
    v1.rend();   // reverse end.

    // Sorting.
    sort(v1.begin(), v1.end()); // sort in increasing order.
    sort(v1.begin(), v1.end(), greater<int>());

    // search in binary search.
    cout << binary_search(v1.begin(), v1.end(), 55) << endl;
    cout << find(v1.begin(), v1.end(), 54) - v1.begin() << endl;

    //
    return 0;
}
