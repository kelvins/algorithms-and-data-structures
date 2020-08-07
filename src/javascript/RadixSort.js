/**
 * @param {number[]} vector 
 */
function RadixSort(vector) {
    let i = 0;
    let b = new Int32Array(vector.length);
    let bigger = vector[0];
    let exp = 1;

    for (i = 0; i < vector.length; i++) {
        if (vector[i] > bigger)
            bigger = vector[i];
    }

    while(parseInt(bigger / exp) > 0){
        let bucket = new Int32Array(10);

        for (i = 0; i < vector.length; i++)
            bucket[parseInt(parseInt((vector[i] / exp)) % 10)]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = vector.length - 1; i >= 0; i--)
            b[--bucket[parseInt(parseInt((vector[i] / exp)) % 10)]] = vector[i];
        for (i = 0; i < vector.length; i++)
            vector[i] = b[i];
        
        exp *= 10;
    }
}

function main() {
    const MAX_LENGTH = 20;
    let vector = [];
    let values = "[";
    for (let index = 0; index < MAX_LENGTH; index++) {
        let value = Math.floor(Math.random() * 99);  // 0 - 99
        vector.push(value);
        values += `${value}, `;
    }
    values += "]";

    console.log(values);

    RadixSort(vector);
    values = "[";
    vector.forEach(v => values+=`${v}, `);
    values += "]";
    console.log(values);
}

main();