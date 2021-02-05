#include <iostream>
using namespace std;

void reverseStr(string &s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left < right)
        swap(s[left++], s[right--]);
}
// Time- O(n)
// Space- O(1)

int main()
{
    string str = "geeksforgeeks";
    reverseStr(str);
    cout << str;
    return 0;
}
