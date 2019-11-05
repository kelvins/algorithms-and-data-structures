/* Código Salgado Castañeda Carlos Eduardo 
Vazquez Pompa Noe 
*/ #include <stdio.h> 
#include <limits.h> 
// Number of vertices in the graph 
#define V 9 
// A utility function to find the vertex with minimum key value, from 
// the set of vertices not yet included in MST 
int minKey(int key[], bool mstSet[]) 
{ 
// Initialize min value 
int min = INT_MAX, min_index; 
for (int v = 0; v < V; v++) 
if (mstSet[v] == false && key[v] < min) 
min = key[v], min_index = v; 
return min_index; 
} // A utility function to print the constructed MST stored in parent[] 
int printMST(int parent[], int n, int graph[V][V]) 
{ 
int peso=0; 
Salgado Castañeda Carlos Eduardo Vazquez Pompa Noe 
printf("\nArista | Peso \t|\n"); 
for (int i = 1; i < V; i++) 
{ 
printf("%d - %d | %d \t|\n", parent[i], i, graph[i][parent[i]]); 
peso+=graph[i][parent[i]]; 
} 
printf("Peso total: %d\n",peso); 
} /* Hacer una matriz de 20x9 de strings, cada columna corresponde a cada vértice 
, la 1a columna para el vértice en curso (o seleccionado por su llave-etiqueta mínima), 
y cada fila de la matriz corresponde a cada iteración del algoritmo, cada celda se actualiza (si es que hay) 
con el par (vértice parent y valor respectivo) 
*/ 
// Function to construct and print MST for a graph represented using adjacency 
// matrix representation 
void primMST(int graph[V][V]) 
{ 
int parent[V]; // Array to store constructed MST 
int key[V]; // Key values used to pick minimum weight edge in cut 
bool mstSet[V]; // To represent set of vertices not yet included in MST 
printf("Actual\t|"); 
for (int i = 0; i < V; i++) 
{ 
printf(" %c\t|",'a'+i ); 
} 
Salgado Castañeda Carlos Eduardo Vazquez Pompa Noe 
printf("\n"); 
// Initialize all keys as INFINITE 
for (int i = 0; i < V; i++) 
key[i] = INT_MAX, mstSet[i] = false; 
// Always include first 1st vertex in MST. 
key[0] = 0; // Make key 0 so that this vertex is picked as first vertex 
parent[0] = -1; // First node is always root of MST 
// The MST will have V vertices 
for (int count = 0; count < V-1; count++) 
{ 
// Pick the minimum key vertex from the set of vertices 
// not yet included in MST 
int u = minKey(key, mstSet); 
// Add the picked vertex to the MST Set 
mstSet[u] = true; 
printf(" %d \t|",key[u]); 
// Update key value and parent index of the adjacent vertices of 
// the picked vertex. Consider only those vertices which are not yet 
// included in MST 
for (int v = 0; v < V; v++) 
{ 
// graph[u][v] is non zero only for adjacent vertices of m 
// mstSet[v] is false for vertices not yet included in MST 
// Update the key only if graph[u][v] is smaller than key[v] 
if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
Salgado Castañeda Carlos Eduardo Vazquez Pompa Noe 
{ 
parent[v] = u, key[v] = graph[u][v]; 
printf(" {%d,%d} |",key[v],parent[v]); 
} 
else 
{ 
printf(" 0\t|"); 
} 
} 
printf("\n"); 
} 
// print the constructed MST 
printMST(parent, V, graph); 
} // driver program to test above function 
int main() 
{ 
int graph[V][V] = { 
{0,4,0,0,0,0,0,8,0}, 
{4,0,8,0,0,0,0,11,0}, 
{0,8,0,7,0,4,0,0,2}, 
{0,0,7,0,9,14,0,0,0}, 
{0,0,0,9,0,10,0,0,0}, 
{0,0,4,14,10,0,2,0,0}, 
{0,0,0,0,0,2,0,1,6}, 
Salgado Castañeda Carlos Eduardo Vazquez Pompa Noe 
{8,11,0,0,0,0,1,0,7}, 
{0,0,2,0,0,0,6,7,0} 
}; 
// Print the solution 
primMST(graph); 
return 0; 
} 
