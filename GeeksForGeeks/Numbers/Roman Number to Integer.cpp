#include <iostream>
using namespace std;

int getValue(char s)
{
    if (s == 'I')
        return 1;
    if (s == 'V')
        return 5;
    if (s == 'X')
        return 10;
    if (s == 'L')
        return 50;
    if (s == 'C')
        return 100;
    if (s == 'D')
        return 500;
    if (s == 'M')
        return 1000;
    return -1;
}

int romanToDecimal(string str)
{
    int result = getValue(str[str.length() - 1]);
    for (int i = str.length() - 2; i >= 0; i--)
    {
        if (getValue(str[i]) < getValue(str[i + 1]))
            result -= getValue(str[i]);
        else
            result += getValue(str[i]);
    }
    return result;
}

int main()
{
    string str = "MCMIV";
    cout << romanToDecimal(str);
}