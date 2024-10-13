#include <iostream>
#include <vector>

#define VERTICES 6
#define INF -1

std::vector<bool> visited(VERTICES, false); // Array to track visited vertices
int components = 0;

// Adjacency matrix representing the graph
int matrix[VERTICES][VERTICES] = {{0, INF, 1, INF, INF, INF},
                                  {INF, 0, INF, 1, 1, INF},
                                  {1, INF, 0, INF, INF, INF},
                                  {INF, 1, INF, 0, 1, 1},
                                  {INF, 1, INF, 1, 0, 1},
                                  {INF, INF, INF, 1, 1, 0}};

// Recursive method to find connected components using adjacency matrix
void findConnectedComponents(int current)
{
    for (int i = 0; i < VERTICES; i++)
    {
        if (!visited[i] && matrix[current][i] == 1)
        {
            visited[i] = true;
            components++;
            std::cout << "(" << i << ")-";
            findConnectedComponents(i);
        }
    }
}

int main()
{
    // Initialize all vertices as unvisited
    for (int i = 0; i < VERTICES; i++)
        visited[i] = false;

    // For each vertex, if it is unvisited, start a DFS and count components
    for (int i = 0; i < VERTICES; i++)
    {
        if (!visited[i])
        {
            components = 0;
            visited[i] = true;
            std::cout << "Starting at vertex (" << i << ")-";
            findConnectedComponents(i);
            std::cout << "\nNumber of connected components starting from vertex " << i << ": " << components << "\n\n";
        }
    }

    return 0;
}
