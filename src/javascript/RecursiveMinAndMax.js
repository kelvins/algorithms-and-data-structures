const MAX_LENGTH = 10;

/**
 * @param {number[]} vector 
 * @param {number} min 
 * @param {number} max 
 * @param {number} index 
 */
function MinMaxRecursive(vector, min, max, index){
    if (vector[index] < min) min = vector[index];
    if (vector[index] > max) max = vector[index];

    if (index < vector.length - 1) {
        const result = MinMaxRecursive(vector, min, max, index + 1);
        min = result.min;
        max = result.max;
    }

    return {
        min, 
        max
    }
}

function main(){
    let vector = [];
    let values = "[";
    for (let index = 0; index < MAX_LENGTH; index++) {
        let value = Math.floor(Math.random() * 99);  // 0 - 99
        vector.push(value);
        values += `${value}, `;
    }
    values += "]"

    console.log(values);
    const result = MinMaxRecursive(vector, vector[0], vector[0], 1);
    console.log(`Min: ${result.min}\nMax: ${result.max}`);
}

main();