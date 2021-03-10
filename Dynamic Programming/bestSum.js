const bestSum = (targetSum, numbers, memo = {}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    let shortestCombination = null;

    for (let num of numbers) {
        let remainder = targetSum - num;
        let remainderCombination = bestSum(remainder, numbers, memo);
        if (remainderCombination !== null) {
            let combination = [...remainderCombination, num];
            if (shortestCombination === null || combination.length < shortestCombination.length)
                shortestCombination = combination;
        }
    }
    memo[targetSum] = shortestCombination;
    return shortestCombination;
};
// m - target sum
// n - array length
// Height/Level of tree = m
// Branching Factor = n
// Time - O((n^m)*m) to O(m*n*m)
// Space - O(m*m) to O(m*m)

console.log(bestSum(7, [2, 3]));
console.log(bestSum(7, [5, 3, 4, 7]));
console.log(bestSum(7, [2, 4]));
console.log(bestSum(8, [2, 3, 5]));
console.log(bestSum(300, [7, 14]));
