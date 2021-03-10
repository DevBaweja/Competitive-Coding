const canSum = (targetSum, numbers, memo = {}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return true;
    if (targetSum < 0) return false;

    for (let num of numbers) {
        let remainder = targetSum - num;
        if (canSum(remainder, numbers, memo)) {
            memo[remainder] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
};
// m - target sum
// n - array length
// Height/Level of tree = m
// Branching Factor = n
// Time - O(n^m) to O(m*n)
// Space - O(m) to O(m)

console.log(canSum(7, [2, 3]));
console.log(canSum(7, [5, 3, 4, 7]));
console.log(canSum(7, [2, 4]));
console.log(canSum(8, [2, 3, 5]));
console.log(canSum(300, [7, 14]));
