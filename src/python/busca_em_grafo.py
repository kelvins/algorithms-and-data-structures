# Graphs - BFS and DFS Algorithms in Python

from collections import deque


class Graph:
    """Define a graph using an adjacency matrix.

    Args:
    edges (list): a list of lists where the index represents the vertex,
    and each element in the list is the neighbor.
    """

    def __init__(self, edges: list):
        self.adj = [[] for _ in range(len(edges))]
        self.add_edges(edges)

    def add_edges(self, edges: list) -> None:
        """Adds all the edges to the graph.

        Args:
            edges (list): the list containing all the edge definitions of the graph.
        """
        for i in range(len(edges)):
            for j in range(len(edges[i])):
                self._add_edge(i, edges[i][j])

    def _add_edge(self, u: int, v: int) -> None:
        """Adds the edge to the adjacency matrix.

        Args:
            u (int): vertex u
            v (int): vertex v
        """
        if v not in self.adj[u]:
            self.adj[u].append(v)

        if u not in self.adj[v]:
            self.adj[v].append(u)

    def bfs(self, start: int) -> list:
        """Performs breadth-first search starting from the vertex "start."

        Args:
            start (int): the starting vertex

        Returns:
            list: a list containing the order of visited vertices.
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
        """Performs depth-first search starting from the vertex "start."

        Args:
            start (int): the starting vertex

        Returns:
            list: a list containing the order of visited vertices.
        """
        visited = []
        visited.append(start)
        stack = [start]

        while stack:
            u = stack.pop()

            if u not in visited:
                visited.append(u)

            for v in reversed(self.adj[u]):
                if v not in visited:
                    stack.append(v)


        return visited


edges = [
    [1, 2, 5],  # Neighbors of vertex 0.
    [0, 2],  # Neighbors of vertex 1.
    [0, 1, 3, 4],  # Neighbors of vertex 2.
    [2, 4, 5],  # Neighbors of vertex 3.
    [2, 3],  # Neighbors of vertex 4.
    [0, 3]  # Neighbors of vertex 5.
]

graph = Graph(edges)
print(graph.adj)
print(graph.bfs(0))
print(graph.dfs(0))
