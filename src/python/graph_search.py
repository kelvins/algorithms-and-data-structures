# Grafos - Algoritmos de BFS e DFS em Python

from collections import deque


class Graph:
    """Define um graph utilizando matrix de adjacências.

    Args:
        edges (list): uma list de lists onde o index é o
                        vertex e cada element da list é o neighbor
    """

    def __init__(self, edges: list):
        self.adj = [[] for _ in range(len(edges))]
        self.adiciona_arestas(edges)

    def adiciona_arestas(self, edges: list) -> None:
        """Adiciona todas as edges ao graph

        Args:
            edges (list): a list contendo todas as definições de edges do graph
        """
        for i in range(len(edges)):
            for j in range(len(edges[i])):
                self.__adiciona_aresta(i, edges[i][j])

    def __adiciona_aresta(self, u: int, v: int) -> None:
        """Adiciona a edge na matrix de adjacência

        Args:
            u (int): vertex u
            v (int): vertex v
        """
        if v not in self.adj[u]:
            self.adj[u].append(v)

        if u not in self.adj[v]:
            self.adj[v].append(u)

    def bfs(self, start: int) -> list:
        """Executa a search em width a partir do vertex start

        Args:
            start (int): vertex start

        Returns:
            list: list com a order de vertices visited
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
        """Executa a search em depth a partir do vertex start

        Args:
            start (int): vertex start

        Returns:
            list: list com a order de vertices visited
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
    [1, 2, 5],  # Vizinhos do vertex 0.
    [0, 2],  # Vizinhos do vertex 1.
    [0, 1, 3, 4],  # Vizinhos do vertex 2.
    [2, 4, 5],  # Vizinhos do vertex 3.
    [2, 3],  # Vizinhos do vertex 4.
    [0, 3],  # Vizinhos do vertex 5.
]

graph = Graph(edges)
print(graph.adj)
print(graph.bfs(0))
print(graph.dfs(0))
