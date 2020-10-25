#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> V;
    V.push_back(1);
    V.push_back(2);
    V.push_back(3);

    // Return true or false
    if (V.empty())
        cout << "Container is empty." << endl;

    // Return size of Container
    cout << V.size() << endl;

    // Copy Constructor
    vector<int> VN(V);

    for (vector<int>::iterator itr = VN.begin(); itr != VN.end(); ++itr)
        cout << *itr << " ";

    // Clear all items from Container
    V.clear();

    // Swap two Container
    VN.swap(V);
}