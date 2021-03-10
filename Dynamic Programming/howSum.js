const howSum = (targetSum, numbers, memo = {}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    for (let num of numbers) {
        let remainder = targetSum - num;
        let remainderCombination = howSum(remainder, numbers, memo);
        if (remainderCombination !== null) {
            memo[targetSum] = [...remainderCombination, num];
            return memo[targetSum];
        }
    }
    memo[targetSum] = null;
    return null;
};
// m - target sum
// n - array length
// Height/Level of tree = m
// Branching Factor = n
// Time - O((n^m)*m) to O(m*n*m)
// Space - O(m) to O(m*m)

console.log(howSum(7, [2, 3]));
console.log(howSum(7, [5, 3, 4, 7]));
console.log(howSum(7, [2, 4]));
console.log(howSum(8, [2, 3, 5]));
console.log(howSum(300, [7, 14]));
