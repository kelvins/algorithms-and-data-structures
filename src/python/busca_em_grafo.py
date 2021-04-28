class Grafo():
    def __init__(self, arestas):
        self.adj = [[] for _ in range(len(arestas))]
        self.adiciona_arestas(arestas)

    def get_vertices(self):
        vertices = set()
        for vizinhos in range(len(self.adj)):
            for elementos in self.adj[vizinhos]:
                vertices.add(elementos)
        return list(vertices)

    def get_arestas(self):
        return [(k, v) for k in self.adj.keys() for v in self.adj[k]]

    def adiciona_arestas(self, arestas):
        for i in range(len(arestas)):
            for j in range(len(arestas[i])):
                self.adiciona_aresta(i, arestas[i][j])

    def adiciona_aresta(self, u, v):
        if v not in self.adj[u]:
            self.adj[u].append(v)

        if u not in self.adj[v]:
            self.adj[v].append(u)

    def existe_aresta(self, u, v):
        return len(self.adj) >= u and v in self.adj[u]

    def __len__(self):
        return len(self.adj)

    def __getitem__(self, v):
        return self.adj[v]

    def bfs(self, u):
        visitados, fila = [], [u]
        while fila:
            vertice = fila.pop(0)
            if vertice not in visitados:
                visitados.append(vertice)
                for element in self.adj[vertice]:
                    if element not in visitados:
                        fila.append(element)

        return visitados

    def dfs(self, u):
        visitados = []
        falta_visitar = [u]
        while falta_visitar:
            vertice = falta_visitar.pop()
            for vizinho in self.adj[vertice]:
                if vizinho not in visitados:
                    visitados.append(vizinho)
                    falta_visitar.append(vizinho)
        return visitados


arestas = [[1, 2, 5],     # Vizinhos do vértice 0.
           [0, 2],        # Vizinhos do vértice 1.
           [0, 1, 3, 4],  # Vizinhos do vértice 2.
           [2, 4, 5],     # Vizinhos do vértice 3.
           [2, 3],        # Vizinhos do vértice 4.
           [0, 3]         # Vizinhos do vértice 5.
           ]

grafo = Grafo(arestas)
print(grafo.adj)
print(grafo.get_vertices())
print(grafo.existe_aresta(4, 1))
print(grafo.bfs(0))
print(grafo.dfs(0))
