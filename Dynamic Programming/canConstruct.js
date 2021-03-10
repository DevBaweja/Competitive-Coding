const canConstruct = (target, wordBank) => {
    if (target === '') return true;

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            let suffix = target.slice(word.length);
            if (canConstruct(suffix, wordBank)) {
                return true;
            }
        }
    }
    return false;
};

console.log(canConstruct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd']));
console.log(canConstruct('skateboard', ['bo', 'rd', 'ate', 't', 'ska', 'sk', 'boar']));
console.log(canConstruct('enterpotentpot', ['a', 'p', 'ent', 'enter', 'ot', 'o', 't']));
console.log(canConstruct('eeeeeeeeeeeeeeeeeeeeeeeeeeeef', ['e', 'ee', 'eee', 'eeee', 'eeeee', 'eeeeee']));
