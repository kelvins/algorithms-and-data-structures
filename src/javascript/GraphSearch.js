/*
*   (A)---------------(B)-------------(E)---------------(F)
*    |                 |               |                 |
*    |                 |               |                 |
*    |                 |               |                 | 
*   (C)---------------(D)-------------(G)                |
*                      |                                 |
*                      -----------------------------------
*
*	7 Vertex
*	9 Edges
*
*/

class No {
    /**
     * @type {Number}
     */
    static MAX_VERTEX;
    /**
     * @type {Number}
     */
    static MAX_EDGES;

    static constructor() {
        this.setMaxVertex(7);
    }

    /** 
     * @param {Number} n Max Vertex
     * 
     * @description When setting the maximum vertex, the maximum edges are automatically calculated
     */
    static setMaxVertex(n) {
        this.MAX_VERTEX = n;
        this.MAX_EDGES = (n * (n - 1));
    }

    /**
     * @type {Array<No>}
     */
    noNeighbors;

    /**
     * @param {Number|String} id 
     */
    constructor(id) {
        this.id = id;
        this.numberNeighbors = 0;
        this.visited = false;
        this.noNeighbors = [];
    }

    /**
     * @param {No} vertexCurrent
     * @param {No} vertexNeighbor
     */
    static linkVertex(vertexCurrent, vertexNeighbor) {
        // Adds the new neighbor to the list of neighbors
        vertexCurrent.noNeighbors.push(vertexNeighbor);
        vertexCurrent.numberNeighbors++;

        vertexNeighbor.noNeighbors.push(vertexCurrent);
        vertexNeighbor.numberNeighbors++;
    }
}

class GraphSearch {

    /**
     * In-Depth Search - DFS - Depth First Search
     * Cycles through all neighbors that were first connected to the vertex
     * 
     * @param {No} vertexOrigin 
     * @param {No} vertexDestiny 
     * @param {Number} visited Position visited
     * 
     * @returns {number} -1 Not found destiny or depth position value
     */
    inDepthSearch(vertexOrigin, vertexDestiny, visited) {
        vertexOrigin.visited = true;

        // If it is the desired destination, it will return
        if (vertexOrigin.id === vertexDestiny.id) return visited;

        let aux = 0;

        // While there is neighbor
        while (vertexOrigin.noNeighbors[aux]) {
            if (vertexOrigin.noNeighbors[aux].visited === false) {
                // Recursively calls passing a new neighbor as a start, that is, it will go through all its neighbors, and so on, successively
                const result = this.inDepthSearch(vertexOrigin.noNeighbors[aux], vertexDestiny, visited + 1);

                // If the result is different from -1, then the target value was found
                if (result !== -1) return result;

            }

            // Next of list
            aux++;
        }

        // Vertex not found
        return -1;
    }

    /**
     * 
     * @param {No} vertexOrigin 
     * @param {No} vertexDestiny 
     * 
     * @returns {number} -1 Not found destiny or depth position value
     */
    widthSearch(vertexOrigin, vertexDestiny) {
        let startQueue = 0;
        let lengthQueue = 1;

        /**
         * @type {Array<No>} Vertex queue be compared
         */
        let queue = new Array(No.MAX_VERTEX);
        queue[startQueue] = vertexOrigin;

        while (startQueue < lengthQueue) {
            // If it is the desired destination, it will return
            if (queue[startQueue].id === vertexDestiny.id) return startQueue;

            /*
            * For all neighbors of the vertex that is about to 'exit' the queue:
            * Mark everyone as visited, so as not to put them in the queue again, and then put them in the queue, and increase the size of the queue.
            */
            for (let i = 0; i < queue[startQueue].numberNeighbors; i++) {
                const vertexCurrent = queue[startQueue];
                if (!vertexCurrent.noNeighbors[i].visited) {
                    vertexCurrent.noNeighbors[i].visited = true;
                    queue[lengthQueue] = vertexCurrent.noNeighbors[i];
                    lengthQueue++;
                }
            }

            // Increments 1 at the beginning of the queue, as if it excluded the first one who entered the queue (FIFO - First In First Out)
            startQueue++;
        }

        return -1;
    }
}

function main() {
    // Graph - set of independent vertices
    let A = new No('A');
    let B = new No('B');
    let C = new No('C');
    let D = new No('D');
    let E = new No('E');
    let F = new No('F');
    let G = new No('G');

    // Connects all vertex according to the GRAPH shown in the introduction
    No.linkVertex(A, B);
    No.linkVertex(A, C);
    No.linkVertex(B, D);
    No.linkVertex(B, E);
    No.linkVertex(C, D);
    No.linkVertex(D, F);
    No.linkVertex(D, G);
    No.linkVertex(E, F);
    No.linkVertex(E, G);

    const graphSearch = new GraphSearch();

    let distance = graphSearch.inDepthSearch(A, G, 0);
    if (distance !== -1)
        console.log(`DFS - Distance: ${distance}`);
    else
        console.log("DFS - Not found.");

    // Clears all visits
    A.visited = false;
    B.visited = false;
    C.visited = false;
    D.visited = false;
    E.visited = false;
    F.visited = false;
    G.visited = false;

    distance = graphSearch.widthSearch(A, G);
    if (distance !== -1)
        console.log(`BFS - Distance: ${distance}`);
    else
        console.log("BFS - Not found.");
}

main();