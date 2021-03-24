// Q1. f(n) = sqrt(n)
// f^x(n) = f(f(f(f(... x times(n)))))
// Find x such that f^x(n) = 2

// Q2. {floor(n/1), floor(n/2), floor(n/3), ... floor(n/n)}
// How many distinct values does this set have

// n = 10
// floor(10/1) = 10
// floor(10/2) = 5
// floor(10/3) = 3
// floor(10/4) = 2
// floor(10/5) = 2
// floor(10/6) = 1
// floor(10/7) = 1
// floor(10/8) = 1
// floor(10/9) = 1
// floor(10/10) = 1
// {10, 5, 3, 2, 2, 1, 1, 1, 1 , 1} = 5

// sqrt(n)

// n/1 > n/2 > n/3 ...> n/sqrt(n) > ... > 2 > 1

// n/1 = a_1
// n/2 = a_2
// ...
// n/(sqrt(n)-1) = a_{sqrt(n)-1}

// ^(sqrt(n))

// n/sqrt(n) ~ sqrt(n)
// n/(sqrt(n)+1) ~
// n/(sqrt(n)+2) ~
// ...
// n/(n-1) ~
// n/n = 1

// ^(sqrt(n))

// sqrt(n)+sqrt(n) = 2*sqrt(n) = O(sqrt(n))