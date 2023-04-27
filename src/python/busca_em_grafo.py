# Grafos - Algoritmos de BFS e DFS em Python
# Bruno Dantas de Paiva - 2021
# https://github.com/DantasB

from collections import deque


class Grafo:
    """Define um grafo utilizando matriz de adjacências.

    Args:
        arestas (list): uma lista de listas onde o indice é o
                        vértice e cada elemento da lista é o vizinho
    """

    def __init__(self, arestas: list):
        self.adj = [[] for _ in range(len(arestas))]
        self.adiciona_arestas(arestas)

    def adiciona_arestas(self, arestas: list) -> None:
        """Adiciona todas as arestas ao grafo

        Args:
            arestas (list): a lista contendo todas as definições de arestas do grafo
        """
        for i in range(len(arestas)):
            for j in range(len(arestas[i])):
                self.__adiciona_aresta(i, arestas[i][j])

    def __adiciona_aresta(self, u: int, v: int) -> None:
        """Adiciona a aresta na matriz de adjacência

        Args:
            u (int): vértice u
            v (int): vértice v
        """
        if v not in self.adj[u]:
            self.adj[u].append(v)

        if u not in self.adj[v]:
            self.adj[v].append(u)

    def bfs(self, start: int) -> list:
        """Executa a busca em largura a partir do vértice start

        Args:
            start (int): vértice start

        Returns:
            list: lista com a ordem de vértices visitados
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
        """Executa a busca em profundidade a partir do vértice start

        Args:
            start (int): vértice start

        Returns:
            list: lista com a ordem de vértices visitados
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
    [1, 2, 5],  # Vizinhos do vértice 0.
    [0, 2],  # Vizinhos do vértice 1.
    [0, 1, 3, 4],  # Vizinhos do vértice 2.
    [2, 4, 5],  # Vizinhos do vértice 3.
    [2, 3],  # Vizinhos do vértice 4.
    [0, 3],  # Vizinhos do vértice 5.
]

grafo = Grafo(arestas)
print(grafo.adj)
print(grafo.bfs(0))
print(grafo.dfs(0))
