// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// a structure to represent a weighted edge in graph
struct Edge
{
int src, dest, weight;
};
// a structure to represent a connected, undirected
// and weighted graph
struct Graph
{
// V-> Number of vertices, E-> Number of edges
int V, E;
// graph is represented as an array of edges.
// Since the graph is undirected, the edge
// from src to dest is also edge from dest
// to src. Both are counted as 1 edge here.
struct Edge* edge;
};
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
struct Graph* graph = new Graph;
graph->V = V;
graph->E = E;
graph->edge = new Edge[E];
return graph;
}
// A structure to represent a subset for union-find
struct subset
{
int parent;
int rank;
};

 

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
// find root and make root as parent of i
// (path compression)
if (subsets[i].parent != i)
subsets[i].parent = find(subsets, subsets[i].parent);
return subsets[i].parent;
}
int **ActualizaRestantes(int **Matriz,int e,int V,int E)
{
for (e ; e != E; e++)
{
for (int i = 0; i < V; ++i)
{
Matriz[e][i]=Matriz[e-1][i];
}
}
return Matriz;
}
int **Actualiza(int **Matriz,int e,int V)
{

for (int i = 0; i < V; ++i)
{
Matriz[e][i]=Matriz[e-1][i];
}
return Matriz;
}
// A function that does union of two sets of x and y
// (uses union by rank)
int **Union(struct subset subsets[], int x, int y,int e, int **Matriz,int V)
{
int xroot = find(subsets, x);
int yroot = find(subsets, y);
// Attach smaller rank tree under root of high
// rank tree (Union by Rank)
if (subsets[xroot].rank < subsets[yroot].rank)
{
 

subsets[xroot].parent = yroot;
Matriz[e][xroot]=yroot;
for (int i = 0; i < V; ++i)
{
if (Matriz[e][i]==xroot)
{
Matriz[e][i]=yroot;
}
}
}
else if (subsets[xroot].rank > subsets[yroot].rank)
{
subsets[yroot].parent = xroot;
Matriz[e][yroot]=xroot;
for (int i = 0; i < V; ++i)
{
if (Matriz[e][i]==yroot)
{
Matriz[e][i]=xroot;
}
}
}
// If ranks are same, then make one as root and
// increment its rank by one
else
{

subsets[yroot].parent = xroot;
Matriz[e][yroot]=xroot;
for (int i = 0; i < V; ++i)
{
if (Matriz[e][i]==yroot)
{
Matriz[e][i]=xroot;
}
}
subsets[xroot].rank++;
}
return Matriz;
}
 

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
struct Edge* a1 = (struct Edge*)a;
struct Edge* b1 = (struct Edge*)b;
return a1->weight > b1->weight;
}
int **Inicializa( int V,int E)
{
int **Matriz2;
Matriz2 = new int*[E];
for (int i = 0; i < E; i++)
{
Matriz2[i] = new int [V];
for (int j= 0; j < V; j++)
{
Matriz2[i][j]=j;
}
}
return Matriz2;
}

void Imprime(int **Matriz,int V,int E)
{
printf("\nMatriz de actualizacion de padres\n");
printf("\nArista\t|");
for (int i = 0; i < V; ++i)
{
printf("\t%d|",i );
}
for (int i = 0; i < E; i++)
{
printf("\n%d\t|",i);
for (int j= 0; j < V; j++)
{
printf("\t%d|",Matriz[i][j]);
}
}
printf("\n");
}
 

// The main function to construct MST using Kruskal's algorithm
int **KruskalMST(struct Graph* graph)
{
int V = graph->V;
struct Edge result[V]; // Tnis will store the resultant MST
int e = 0; // An index variable, used for result[]
int i = 0; // An index variable, used for sorted edges
int **Matriz;
Matriz=Inicializa(graph->V,graph->E);
// Step 1: Sort all the edges in non-decreasing
// order of their weight. If we are not allowed to
// change the given graph, we can create a copy of
// array of edges
qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
// Allocate memory for creating V ssubsets
struct subset *subsets =
(struct subset*) malloc( V * sizeof(struct subset) );
// Create V subsets with single elements
for (int v = 0; v < V; ++v)
{
subsets[v].parent = v;
subsets[v].rank = 0;
}
// Number of edges to be taken is equal to V-1
while (e < V - 1)
{
// Step 2: Pick the smallest edge. And increment
// the index for next iteration

struct Edge next_edge = graph->edge[i++];
int x = find(subsets, next_edge.src);
int y = find(subsets, next_edge.dest);
// If including this edge does't cause cycle,
// include it in result and increment the index
// of result for next edge
if (x != y)
{
result[e++] = next_edge;
Matriz=Union(subsets, x, y,e,Matriz,V);
Matriz=Actualiza(Matriz,e+1,V);
 

}

// Else discard the next_edge
}
Matriz=ActualizaRestantes(Matriz,e+1,V,graph->E);
// print the contents of result[] to display the
// built MST
printf("Following are the edges in the constructed MST\n");
for (i = 0; i < e; ++i)
printf("%d -- %d == %d\n", result[i].src, result[i].dest,
result[i].weight);
return Matriz;
}
// Driver program to test above functions
int main()
{
/* Let us create following weighted graph

10
0--------1
| \ |
6| 5\ |15
| \ |
2--------3
4 */

int V = 12; // Number of vertices in graph
int E = 23; // Number of edges in graph
struct Graph* graph = createGraph(V, E);
int **Matriz;
Matriz=Inicializa(V,E);
// add edge 0-1
graph->edge[0].src = 0;
graph->edge[0].dest = 1;
graph->edge[0].weight = 3;
// add edge 0-2
graph->edge[1].src = 0;
graph->edge[1].dest = 3;
graph->edge[1].weight = 10;
// add edge 0-3
graph->edge[2].src = 0;
 

graph->edge[2].dest = 4;
graph->edge[2].weight = 2;
// add edge 1-3
graph->edge[3].src = 1;
graph->edge[3].dest = 2;
graph->edge[3].weight = 4;
// add edge 2-3
graph->edge[4].src = 1;
graph->edge[4].dest = 4;
graph->edge[4].weight =9;
graph->edge[5].src = 2;
graph->edge[5].dest = 5;
graph->edge[5].weight =5 ;
graph->edge[6].src = 2;
graph->edge[6].dest = 4;
graph->edge[6].weight = 6;
graph->edge[7].src = 3;
graph->edge[7].dest = 4;
graph->edge[7].weight =4 ;
graph->edge[8].src = 3;
graph->edge[8].dest = 6;
graph->edge[8].weight = 4;
graph->edge[9].src = 4;
graph->edge[9].dest = 5;
graph->edge[9].weight = 3;
graph->edge[10].src = 4;
graph->edge[10].dest = 6;
graph->edge[10].weight =6 ;
graph->edge[11].src = 4;
graph->edge[11].dest = 7;
graph->edge[11].weight =2 ;
graph->edge[12].src = 4;
graph->edge[12].dest = 8;
graph->edge[12].weight = 6;
graph->edge[13].src = 5;
graph->edge[13].dest = 8;
 

graph->edge[13].weight =8 ;
graph->edge[14].src = 6;
graph->edge[14].dest = 7;
graph->edge[14].weight =8 ;
graph->edge[15].src = 6;
graph->edge[15].dest = 9;
graph->edge[15].weight =3 ;
graph->edge[16].src = 7;
graph->edge[16].dest = 8;
graph->edge[16].weight =8 ;
graph->edge[17].src = 7;
graph->edge[17].dest = 9;
graph->edge[17].weight = 3;
graph->edge[18].src = 7;
graph->edge[18].dest = 10;
graph->edge[18].weight = 5;
graph->edge[19].src = 7;
graph->edge[19].dest = 11;
graph->edge[19].weight = 7;
graph->edge[20].src = 8;
graph->edge[20].dest = 11;
graph->edge[20].weight = 4;
graph->edge[21].src = 9;
graph->edge[21].dest = 10;
graph->edge[21].weight = 5;
graph->edge[22].src = 10;
graph->edge[22].dest = 11;
graph->edge[22].weight = 2;
Matriz=KruskalMST(graph);
Imprime(Matriz,V,E);
return 0;
}