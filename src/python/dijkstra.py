# Grafos - Algoritmos de Dijkstra em Python
# Bruno Dantas de Paiva - 2021
# https://github.com/DantasB

import heapq


class Grafo:
    """Define a graph using an adjacency matrix.

    Args:
        Edges (list): a list of lists where the index is the
                        vertex, and each element of the list is the neighbor.
    """

    def __init__(self, arestas: list):
        self.adj = [[] for _ in range(len(arestas))]
        self.dist = [99999 for _ in range(len(arestas))]
        self.adiciona_arestas(arestas)

    def adiciona_arestas(self, arestas: list) -> None:
        """  Add all the edges to the grafo

        Args:
            Edges (list): the list containing all the edge definitions of the graph.
        """
        for i in range(len(arestas)):
            for j in range(len(arestas[i])):
                self.__adiciona_aresta(i, arestas[i][j])

    def __adiciona_aresta(self, u: int, v: int) -> None:
        """Add the edge to the adjacency matrix.

        Args:
            u (int): vertex u
            v (int): vertex v
        """
        if v[0] not in self.adj[u]:
            self.adj[u].append([v[1], v[0]])

    def _peso_entre_u_e_v(self, u: int, v: int) -> float:
        """Return the weight between vertices u and v.

        Args:
            u (int): vertex u
            v (int): vertex v

        Returns:
            float: weight between u and v
        """
        for vertice in self.adj[v[1]]:
            if vertice[1] == u:
                return vertice[0]

    def dijkstra(self, start: int) -> list:
        """Returns the list of distances from the start vertex to all vertices.

        Args:
            start (int): initial vertex

        Returns:
            list: list of distances
        """
        distancia = self.dist.copy()
        S = set()  # Set of explored vertices
        distancia[start] = 0

        while True:
            V = set([(i, distancia[i]) for i in range(len(self.adj))])
            diferenca_de_conjuntos = list(V.difference(S))
            if not diferenca_de_conjuntos:
                break

            heapq.heapify(diferenca_de_conjuntos)
            u, distancia_u = heapq.heappop(diferenca_de_conjuntos)

            S.add((u, distancia[u]))
            for v in self.adj[u]:
                if distancia[v[1]] > distancia_u + self._peso_entre_u_e_v(u, v):
                    distancia[v[1]] = distancia_u + self._peso_entre_u_e_v(u, v)

        return distancia


arestas = [
    [[1, 1], [2, 0.3], [5, 0.2]],  # Neighbors of vertex 0.
    [[0, 1], [2, 0.5]],  # Neighbors of vertex 1.
    [[0, 0.3], [1, 0.5], [3, 1.5], [4, 2]],  # Neighbors of vertex 2.
    [[2, 1.5], [4, 1.3], [5, 0.8]],  # Neighbors of vertex 3.
    [[2, 2], [3, 1.3]],  # Neighbors of vertex 4.
    [[0, 0.2], [3, 0.8]],  # Neighbors of vertex 5.

]

grafo = Grafo(arestas)
print(grafo.dijkstra(0))
