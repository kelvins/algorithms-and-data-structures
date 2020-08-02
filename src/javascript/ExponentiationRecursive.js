/**
 * @param {number} base 
 * @param {number} exponent 
 */
function exponentiationRecursive(base, exponent) {
    if (exponent <= 1) return base;
    
    return base * exponentiationRecursive(base, exponent -1);
}

function main(){
    // Sample: 3³ = 3*3*3 = 27
    console.log('Exponentiation 3³ => ', exponentiationRecursive(3, 3));
}

main();