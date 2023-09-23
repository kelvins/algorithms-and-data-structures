/*
*
*	Graphs - Algorithm to calculate the number of connected components in a given Graph
*	Kelvin Salton do Prado - 2015
*
*	GRAPH
*   (0)               (1)-------------(4)---------------(5)
*    |                 |               |                 |
*    |                 |               |                 |
*    |                 |               |                 | 
*   (2)               (3)---------------                 |
*                      |                                 |
*                      -----------------------------------
*
*
*    Adjacency Matrix
*       0  1  2  3  4  5 
*    0  0  -  1  -  -  -
*    1  -  0  -  1  1  -
*    2  1  -  0  -  -  -
*    3  -  1  -  0  1  1
*    4  -  1  -  1  0  1
*	 5  -  -  -  1  1  0
*
*
*	6 Vertices
*	8 Edges
*/

#include <stdio.h>

#define VERTICES 6
#define INF -1

bool visited[VERTICES];
int components = 0;

int matrix[VERTICES][VERTICES]  = { {   0, INF,   1, INF, INF, INF },
                                    { INF,   0, INF,   1,   1, INF },
                                    {   1, INF,   0, INF, INF, INF },
                                    { INF,   1, INF,   0,   1,   1 },
                                    { INF,   1, INF,   1,   0,   1 },
                                    { INF, INF, INF,   1,   1,   0 } };

// Recursive method that finds the connected components from an adjacency matrix
void calculateConnectedComponents(int current){
    for (int i = 0; i < VERTICES; i++){
        if( visited[i] == false && matrix[current][i] == 1 ){
            visited[i] = true;
            components++;
            printf("(%d)-", i);
            calculateConnectedComponents(i);
        }
    }
}

int main(){
    for (int i = 0; i < VERTICES; i++)
        visited[i] = false;

    for (int i = 0; i < VERTICES; i++)
        if( visited[i] == false ){
            components = 0;
            calculateConnectedComponents(i);
            printf("\nNumber of connected components starting from vertex %d: %d\n\n", i, components);
        }
    
    return 0;
}
