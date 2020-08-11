const MAX_LENGTH = 10;

/**
 * @param {number[]} vector 
 */
function heapSort(vector){
    let length = vector.length;
    let i = parseInt(vector.length / 2);
    let temp, father, children;

    while(true) {
        if(i > 0){
            i--;
            temp = vector[i];
        } else {
            length--;
            if (length <= 0) return vector;

            temp = vector[length];
            vector[length] = vector[0];
        }

        father = i;
        children = parseInt((i * 2) + 1);

        while(children < length) {
            if (children + 1 < length && vector[children + 1] > vector[children])
                children++;

            if (vector[children] > temp) {
                vector[father] = vector[children];
                father = children;
                children = parseInt(father * 2 + 1);
            } else break;
        }

        vector[father] = temp;
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

    console.log("Initial -> ", values);

    console.log("Final Vector")
    console.table(heapSort(vector));
}

main();