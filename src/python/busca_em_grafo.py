# Graphs - BFS and DFS Algorithms in Python
# Bruno Dantas de Paiva - 2021
# https://github.com/DantasB

from collections import deque

class Graph:
    """Defines a graph using an adjacency matrix.

    Args:
        edges (list): A list of lists where the index is the
                      vertex, and each element in the list is a neighbor.
    """

    def __init__(self, edges: list):
        self.adj = [[] for _ in range(len(edges))]
        self.add_edges(edges)

    def add_edges(self, edges: list) -> None:
        """Add all edges to the graph.

        Args:
            edges (list): The list containing all edge definitions of the graph.
        """
        for i in range(len(edges)):
            for j in range(len(edges[i])):
                self.__add_edge(i, edges[i][j])

    def __add_edge(self, u: int, v: int) -> None:
        """Add an edge to the adjacency matrix.

        Args:
            u (int): Vertex u
            v (int): Vertex v
        """
        if v not in self.adj[u]:
            self.adj[u].append(v)

        if u not in self.adj[v]:
            self.adj[v].append(u)

    def bfs(self, start: int) -> list:
        """Perform breadth-first search starting from the 'start' vertex.

        Args:
            start (int): Start vertex

        Returns:
            list: List with the order of visited vertices.
        """
        queue = deque()
        queue.append(start)
        visited = []
        visited.append(start)

        while queue:
            u = queue.popleft()

            for v in self.adj[u]:
                if v not in visited:
                    queue.append(v)
                    visited.append(v)

        return visited

    def dfs(self, start: int) -> list:
        """Perform depth-first search starting from the 'start' vertex.

        Args:
            start (int): Start vertex

        Returns:
            list: List with the order of visited vertices.
        """
        visited = []
        visited.append(start)
        stack = [start]

        while stack:
            u = stack.pop()

            if u not in visited:
                visited.append(u)

            for v in self.adj[u][::-1]:
                if v not in visited:
                    stack.append(v)

        return visited


edges = [
    [1, 2, 5],     # Neighbors of vertex 0.
    [0, 2],        # Neighbors of vertex 1.
    [0, 1, 3, 4],  # Neighbors of vertex 2.
    [2, 4, 5],     # Neighbors of vertex 3.
    [2, 3],        # Neighbors of vertex 4.
    [0, 3],        # Neighbors of vertex 5.
]

graph = Graph(edges)
print(graph.adj)
print(graph.bfs(0))
print(graph.dfs(0))

