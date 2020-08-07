const MAX_LENGTH = 10;

/**
 * @param {number[]} vector 
 */
function MinMaxIterative(vector){
    let min = max = vector[0];

    vector.forEach(value => {
        if (value > max) max = value;
        if(value < min) min = value;
    });

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
    const result = MinMaxIterative(vector);
    console.log(`Min: ${result.min}\nMax: ${result.max}`);
}

main();