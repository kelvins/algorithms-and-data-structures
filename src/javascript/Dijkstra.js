/*
 * Graphs - Dijkstra's Algorithm in JavaScript
 * Complexity: Theta(n^2)
 *
 * 1 for all - Non-negative weight edges - Greedy algorithm
 * Finds the shortest path from one vertex (start) to another (destination)
 *
 * Graph with 5 vertices and 6 edges
 *
 *              6
 *   (0)-----------------(1)
 *    |                   |
 * 10 |                   | 2
 *    |         1         |
 *   (2)-----------------(3)
 *    \                  /
 *   3 \                / 8
 *      \              /
 *       -----(4)-----
 *
 *  Distance Matrix
 *    0   1   2   3   4
 * 0  0   6  10   -   -
 * 1  6   0   -   2   -
 * 2 10   -   0   1   3
 * 3  -   2   1   0   8
 * 4  -   -   3   8   0
 *
 *  For infinity values, the value: 4294967295 will be considered
 *  The goal is to start from the initial point (0) and reach the destination (4) via the shortest path
 *  Answer: (0)->(1)->(3)->(2)->(4) = 12
 *
 */

const nVertices = 5; // Defines a constant 5, which is the number of vertices in the graph

// Dijkstra's Algorithm takes the distance matrix and the number of vertices as parameters
function Dijkstra(matrix, n) {
    let visited = new Array(n); // Variable that stores true for visited vertices

    // The value 'i' in the for loop below is not used, as the for loop is only used to traverse the entire number of columns in the matrix
    for (let i = 1; i < n; i++) { // Starts at 1 because there is no need to compare the vertex with itself
        let min, minValue;

        // Loop that goes through all rows in column [0]
        for (let j = 1; j < n; j++) {
            // If the vertex has not been visited yet and the value is smaller than 'minValue'
            if (!visited[j] && (!minValue || matrix[j][0] < minValue)) {
                min = j; // Stores the position of the minimum
                minValue = matrix[j][0]; // Stores the minimum value
            }
        }

        visited[min] = true; // Marks the position of the minimum as visited

        // Loop from 1 to n
        for (let j = 1; j < n; j++) {
            // If the value in column [0] + the value in the current column is smaller than the value in the current row and column [0]
            // Update the first column of the matrix, which will be used for the next iterations

            if (matrix[min][0] + matrix[min][j] < matrix[j][0]) {
                matrix[j][0] = matrix[min][0] + matrix[min][j];
            }
        }
    }
}

function main() {
    let matrix = [];
    let ignore = 4294967295;
    matrix.push([0, 6, 10, ignore, ignore]);
    matrix.push([6, 0, ignore, 2, ignore]);
    matrix.push([10, ignore, 0, 1, 3]);
    matrix.push([ignore, 2, 1, 0, 8]);
    matrix.push([ignore, ignore, 3, 8, 0]);
    console.table(matrix);

    Dijkstra(matrix, nVertices);

    console.log("Total shortest path from vertex 0 to 4: ", matrix[4][0]); // Total shortest path

    // Print the matrix with updated values
    console.log("Matrix:");
    console.table(matrix);
}

main();
