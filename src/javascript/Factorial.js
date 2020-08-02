/**
 * 
 * @param {number} n 
 */
function factorial(n) {
    let result = 1;
    for (let index = n; index > 1; index--)
        result = result * index;

    return result;
}

function main(){
    console.log('Fatorial => ', factorial(3));
}

main();