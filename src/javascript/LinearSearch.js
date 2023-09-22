function linearSearch(array, targetValue) {
    for (let i = 0; i < array.length; i++) {
        if (array[i] == targetValue) {
            return i;
        }
    }
    return -1;
}

var array = [54, 42, 11, 33, 24, 99, 77, 80];
console.log(linearSearch(array, 11));

