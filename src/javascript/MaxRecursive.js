/**
 * Maximum using Division and Conquest
 * @param {Array<Number>} vector 
 * @param {number} start 
 * @param {number} end 
 */
function maxDivisionAndConquest(vector, start, end){
    if (start === end) return vector[start];
    
    const middle = parseInt((start + end) / 2);

    const aux1 = maxDivisionAndConquest(vector, start, middle);
    const aux2 = maxDivisionAndConquest(vector, middle + 1, end);

    if (aux1 > aux2) return aux1;
    else return aux2;
}

const MAX_LENGTH = 10;

/**
 * @param {Array<number>} vector 
 * @param {number} max 
 * @param {number} index 
 */
function max1(vector, max, index){
    if (vector[index] > max) max = vector[index];
    if (index < MAX_LENGTH - 1) max = max1(vector, max, index + 1);
    
    return max;
}

/**
 * @param {Array<number>} vector 
 * @param {number} lengthVector 
 * @returns {number}
 */
function max2(vector, lengthVector){
    if (lengthVector === 1) return vector[0];

    const max = max2(vector, lengthVector - 1);
    if (max > vector[lengthVector - 1]) return max;
    else return vector[lengthVector - 1];
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
    console.log('maxDivisionAndConquest => ', maxDivisionAndConquest(vector, 0, MAX_LENGTH -1));
    console.log('max1 => ', max1(vector, vector[0], 1));
    console.log('max2 => ', max2(vector, MAX_LENGTH));
}

main();