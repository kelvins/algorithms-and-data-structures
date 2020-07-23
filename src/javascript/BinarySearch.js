class BinarySearch {
    iterative(key, orderedVector) {
        if (!(orderedVector instanceof Array) && typeof key !== 'number')
            throw new Error("it is necessary to validate the types of data reported.");

        let inferiorLimit = 0; // first vector index in Javascript
        let upperLimit = orderedVector.length - 1; // last index of the vector in Javascript
        let middle;

        while (inferiorLimit <= upperLimit) {
            middle = parseInt((inferiorLimit + upperLimit) / 2);

            if (key === orderedVector[middle])
                return middle;
            else if (key < orderedVector[middle])
                upperLimit = middle - 1;
            else
                inferiorLimit = middle + 1;
        }

        return -1; // Not found
    }

    recursive(key, orderedVector, leftInferiorLimit, rightUpperLimit) {
        if (typeof key !== 'number' && !(orderedVector instanceof Array) && typeof leftInferiorLimit !== 'number' && typeof rightUpperLimit !== 'number')
            throw new Error("it is necessary to validate the types of data reported.");

        const middle = parseInt((leftInferiorLimit + rightUpperLimit) / 2);
            
        if (key === orderedVector[middle])
            return middle;

        if (leftInferiorLimit >= rightUpperLimit)
            return -1;// Not found
        else if (key > orderedVector[middle]) // 10 < 9
            return this.recursive(key, orderedVector, middle + 1, rightUpperLimit);
        else
            return this.recursive(key, orderedVector, leftInferiorLimit, middle - 1);
    }
}

function main() {
    let vector = []

    for (let index = 1; index <= 50; index++)
        vector.push(index)

    const instance = new BinarySearch();
    const wantedValue = 1;
    try {
        const resultIterative = instance.iterative(wantedValue, vector);
        const resultRecursive = instance.recursive(wantedValue, vector, 0, vector.length);

        const getMessage = value => {
            if (value === -1)
                return "Value not found";
            else
                return `Value found in position ${value}`;
        }

        console.log(`Wanted Value -> ${wantedValue}`);
        console.log(`Iterative -> ${getMessage(resultIterative)}`);
        console.log(`Recursive -> ${getMessage(resultRecursive)}`);
    } catch (error) {
        console.error(error.message);
    }
}

main();