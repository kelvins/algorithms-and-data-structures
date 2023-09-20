# Graphs - BFS and DFS Algorithms in Python

from collections import deque


class Grafo:
    """Define a graph using an adjacency matrix.

    Args:
    edges (list): a list of lists where the index represents the vertex, 
    and each element in the list is the neighbor.
    """

    def __init__(self, arestas: list):
        self.adj = [[] for _ in range(len(arestas))]
        self.adiciona_arestas(arestas)

    def adiciona_arestas(self, arestas: list) -> None:
        """Adds all the edges to the graph.

        Args:
            Edges (list): the list containing all the edge definitions of the graph.
        """
        for i in range(len(arestas)):
            for j in range(len(arestas[i])):
                self.__adiciona_aresta(i, arestas[i][j])

    def __adiciona_aresta(self, u: int, v: int) -> None:
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
        fila = deque()
        fila.append(start)
        visitados = []
        visitados.append(start)

        while fila:
            u = fila.popleft()

            for v in self.adj[u]:
                if v not in visitados:
                    fila.append(v)
                    visitados.append(v)

        return visitados

    def dfs(self, start: int) -> list:
        """Performs depth-first search starting from the vertex "start."

        Args:
            start (int): the starting vertex

        Returns:
            list: a list containing the order of visited vertices.
        """
        visitados = []
        visitados.append(start)
        pilha = [start]

        while pilha:
            u = pilha.pop()

            if u not in visitados:
                visitados.append(u)

            for v in self.adj[u][::-1]:
                if v not in visitados:
                    pilha.append(v)

        return visitados


arestas = [
    [1, 2, 5],  # Neighbors of vertex 0.
    [0, 2],  # Neighbors of vertex 1.
    [0, 1, 3, 4],  # Neighbors of vertex 2.
    [2, 4, 5],  # Neighbors of vertex 3.
    [2, 3],  # Neighbors of vertex 4.
    [0, 3]  # Neighbors of vertex 5.
]

grafo = Grafo(arestas)
print(grafo.adj)
print(grafo.bfs(0))
print(grafo.dfs(0))
