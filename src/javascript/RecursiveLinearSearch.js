/**
 * @param {number[]} vector 
 * @param {number} wanted 
 * @param {number} index 
 */
function recursiveLinearSearch(vector, wanted, index){
    if (index >= 0 && index < vector.length){
        if (vector[index] === wanted) return index;
        else return recursiveLinearSearch(vector, wanted, index + 1);
    }
    throw new Error(`Value: ${wanted} - Not Found`)
}

function main(){
    const vector = [10, 90, 15, 50, 72, 99, 101, 2, 3, 4, 20, 25];
    try {
        console.log(`Wanted: 3\nPosition: ${recursiveLinearSearch(vector, 3, 0)}`);
    } catch (error) {
        console.log(error.message)
    }
}

main();