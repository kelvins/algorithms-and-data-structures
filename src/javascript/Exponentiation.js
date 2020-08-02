/**
 * @param {number} base 
 * @param {number} exponent 
 */
function exponentiation(base, exponent) {
    const baseNumber = base;
    for (let index = 0; index < exponent-1; index++) 
        base *= baseNumber;

    return base;
}

function main(){
    // Sample: 3³ = 3*3*3 = 27
    console.log('Exponentiation 3³ => ', exponentiation(3, 3));
}

main();