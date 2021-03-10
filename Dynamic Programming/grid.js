// Memoization
const grid = (m, n, memo = {}) => {
    const key = m + ',' + n;
    const invkey = n + ',' + m;
    if (key in memo) return memo[key];
    if (invkey in memo) return memo[invkey];

    if (m === 0 || n === 0) return 0;
    if (m === 1 && n === 1) return 1;

    memo[key] = grid(m - 1, n, memo) + grid(m, n - 1, memo);
    return memo[key];
};
// Time  - O(2^(m+n)) to O(m*n)
// Space - O(m+n)

console.log(grid(1, 1));
console.log(grid(2, 3));
console.log(grid(2, 3));
console.log(grid(3, 3));
console.log(grid(18, 18));
