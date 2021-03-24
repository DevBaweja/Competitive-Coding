#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ;
    // Time - O(n^2)

    for (int i = 0; i < n; i++)
        ;
    for (int j = 0; j < m; j++)
        ;
    // Time - O(n+m)

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            ;
    // i = 0, j = 0 to n-1 = n
    // i = 1, j = 1 to n-1 = n-1
    // Time - n+(n-1)+(n-2)+ ... + 1 = n(n-1)/2 = O(n^2)

    for (int i = n; i >= 1; i /= 2)
        ;
    // Time - O(log(n))
    // n -> n/2 -> n/4 -> n/8 -> n/(2)^x
    // n/(2)^x = 1
    // x = log(n)

    for (int i = n; i >= 1; i /= 2)
        for (int j = i; j < m; j++)
            ;
    // Time - O(m*log(n))
    // i = 1, j = 1 to m
    // i = 2, j = 2 to m
    // i = 4, j = 4 to m
    // i = 2^log(n), j = 2^log(n) to m
    // sum of (m-2^i) where i goes from 1 to log(n)
    // m*log(n) - 2^(log(n)+1) = O(m*log(n))

    int a[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n && a[i] < a[j];)
            j++;
    // Time - O(n)
    // i = 0, j = 0 to 5
    // i = 1, j = 5 to 6
    // i = 2, j = 6 to 8
    // i = n-1, j = n-5 to n-1

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            ;
    // Time - O(n*log(n))
    // n + n/2 + n/3 + n/4 + ...+ 1 = n*log(n)

    // sum(i=1 to n) (1/i) = integrating(i=1 to n) (1/i) = (x=n,x=1) log(x) = log(n)-log(1) = log(n)

    bool is_composite[n];
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (is_composite[i])
            continue;
        primes.push_back(i);
        for (int j = i; j <= n; j += i)
            is_composite[j] = 1;
    }
    return 0;
    // Time - O()
    // n/2 + n/3 + n/5 + n/7 + ... = n * (sum of 1/primes) = n*log(log(n))
}

int count_occurrences(int A[], int key, int low, int high)
{
    if (low > high)
        return 0;
    int mid = (low + high) / 2;
    if (A[mid] < key)
        return count_occurrences(A, key, mid + 1, high);
    if (A[mid] < key)
        return count_occurrences(A, key, low, mid - 1);
    return 1 + count_occurrences(A, key, low, mid - 1) + count_occurrences(A, key, mid + 1, high);
}

// Ranges
// N<=10^6 -> O(n) / O(n*log(n))
// N<=10^5 -> O(n*log(n)*log(n))
// N<=10^4 -> O(n^2) / O(n*log(n)*log(n))
// N<=10^3 -> O(n^2) / O(n^2*log(n))
// N<=350 -> O(n^3)
// N<=20 -> O(2^n)
// N<=15 -> O(n^2*2^n)
// N<=10 -> O(n!)
