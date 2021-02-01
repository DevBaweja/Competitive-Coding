#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2{1, 2, 3};
    vector<int> v3(10, 0);

    // int A0[]; - Invalid
    int A1[] = {1, 2, 3};
    int A2[10];
    int *A3 = new int[10];

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        cout << *it << " ";

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    // v1.at(i);

    return 0;
}