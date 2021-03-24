#include <iostream>
using namespace std;

const int n = 100, logn = 7;

// 1 << pos = 2^pos
bool is_bit_on(int &x, int pos)
{
    return (x & (1 << pos)) != 0;
    // (1 << pos)
    // Time - O(1)
    // Bit Shifting
    // pow(2, pos)
    // Time - O(pos) or O(log(pos))
    // Binary Exponentiation O(log(pos))
    // a^b = (a^(b/2))^2, if b is even
    // a^b = (a^(b-1))*a, if b is odd
}
// x ^= y ie x xor y
void flip_bit(int &x, int pos)
{
    x ^= (1 << pos);
}

void increment(int &x)
{
    for (int i = 0; i < logn; i++) // O(position of first 0 in x base 2)
    {
        if (is_bit_on(x, i))
            flip_bit(x, i);
        else
        {
            flip_bit(x, i);
            break;
        }
    }
}
// 110110
// 110111
// 111000
// Time - O(n*log(n))
// Flip bits starting from left(least significant bit) and then flip first 0 and break
// sum(x=0 to n-1) (position of first 0 in x base 2) = O(n)

// n = 8
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111

// n = 2^p
// x = _ _ _ _ _ _ _ 0 = 2^(p-1)
// x = _ _ _ _ _ _ 0 1 = 2^(p-2)
// x = _ _ _ _ _ 0 1 1 = 2^(p-3)

// sum of 2^(p-i) where i goes from 1 to p = 2^0 + 2^1 + 2^2 + ...+ 2^(p-1) = 2^p-1 = 2^p = n

// O(n*log(n)) is correct but it is incomplete information
// O(n) is correct and complete information
// O(sqrt(n)) is not correct
int main()
{
    int counter = 0;
    for (int i = 0; i < n; i++)
        increment(counter);
    cout << counter;
}
