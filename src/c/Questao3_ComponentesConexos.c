/*
*
*	SIN5013 - Semester Content Test Example
*
*	3. Write a program (using one or more methods/functions in code or pseudocode) that, given an undirected graph with n nodes, returns the number of connected components in the graph. This graph can be represented by: (a) a boolean adjacency matrix with n x n cells corresponding to the n nodes of the graph; or represented by: (b) an array of nodes, where each node has an array of neighbors. In this case, consider that Node is a class or structure that has the following fields [or attributes]: numNeighbors (an integer field with the number of neighbors of the respective node), neighbors (an array of pointers to Nodes with numNeighbors elements), visited (a boolean field). Choose the representation that suits you, and if you wish, consider that all variables are global/static. Assume that the variables are already properly initialized/filled.
*
*	Representation:
*	int numNodes = n;
*	boolean adjacencies[][] = new boolean[n][n];
*	boolean visited[] = new boolean[n];
*
*
*	GRAPH
*   (0)               (1)-------------(4)---------------(5)
*    |                 |               |                 |
*    |       (6)       |               |                 |
*    |                 |               |                 | 
*   (2)               (3)---------------                 |
*                      |                                 |
*                      -----------------------------------
*
*
*    Adjacency Matrix
*       0  1  2  3  4  5  6
*    0  0  -  1  -  -  -  -
*    1  -  0  -  1  1  -  -
*    2  1  -  0  -  -  -  -
*    3  -  1  -  0  1  1  -
*    4  -  1  -  1  0  1  -
*	 5  -  -  -  1  1  0  -
*	 6  -  -  -  -  -  -  0
*
*/

#include <stdio.h>

#define numNodes 7
bool visited[numNodes];
bool matrix[numNodes][numNodes] = {{false, false, true, false, false, false, false},
                                   {false, false, false, true, true, false, false},
                                   {true, false, false, false, false, false, false},
                                   {false, true, false, false, true, true, false},
                                   {false, true, false, true, false, true, false},
                                   {false, false, false, true, true, false, false},
                                   {false, false, false, false, false, false, false}};
int components = 0;

void resetVariables() {
    components = 0;
    for (int i = 0; i < numNodes; i++)
        visited[i] = false;
}

void visitNeighbors(int current) {
    for (int i = 0; i < numNodes; i++) {
        if (visited[i] == false && matrix[current][i] == true) {
            visited[i] = true;
            components++;
            printf("(%d)-", i);
            visitNeighbors(i);
        }
    }
}

void calculateConnectedComponents() {
    // Iterate through all 'nodes'/'components'
    for (int i = 0; i < numNodes; i++) {
        components = 0;
        if (visited[i] == false) { // If the component has not been visited yet
            visitNeighbors(i); // Call the method to count connections with neighbors
            printf("Group %d:\nNumber of connected components: %d\n\n", i, components);
        }
    }
}

int main() {
    resetVariables();
    calculateConnectedComponents();

    return 0;
}
