var areNumbersAscending = function (sentence) {
    var words = sentence.split(' ');
    words = words.filter(word => !isNaN(word));
    words = words.map(word => parseInt(word));
    var res = true;
    for (var k = 1; k < words.length; k++) res &= words[k - 1] < words[k];
    return res;
};
