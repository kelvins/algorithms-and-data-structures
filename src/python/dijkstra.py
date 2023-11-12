import heapq


class Graph:
    def __init__(self, edges: list):
        self.adj = [[] for _ in range(len(edges))]
        self.dist = [99999 for _ in range(len(edges))]
        self.add_edges(edges)

    def add_edges(self, edges: list) -> None:
        for i in range(len(edges)):
            for j in range(len(edges[i])):
                self.__add_edge(i, edges[i][j])

    def __add_edge(self, u: int, v: int) -> None:
        if v[0] not in self.adj[u]:
            self.adj[u].append([v[1], v[0]])

    def _weight_between_u_and_v(self, u: int, v: int) -> float:
        for vertex in self.adj[v[1]]:
            if vertex[1] == u:
                return vertex[0]

    def dijkstra(self, start: int) -> list:
        distance = self.dist.copy()
        S = set()  # Set of explored vertices
        distance[start] = 0

        while True:
            V = set([(i, distance[i]) for i in range(len(self.adj))])
            difference_of_sets = list(V.difference(S))
            if not difference_of_sets:
                break

            heapq.heapify(difference_of_sets)
            u, distance_u = heapq.heappop(difference_of_sets)

            S.add((u, distance[u]))
            for v in self.adj[u]:
                if distance[v[1]] > distance_u + self._weight_between_u_and_v(u, v):
                    distance[v[1]] = distance_u + self._weight_between_u_and_v(u, v)

        return distance


if __name__ == "__main__":
    edges = [
        [[1, 1], [2, 0.3], [5, 0.2]],  # Neighbors of vertex 0.
        [[0, 1], [2, 0.5]],  # Neighbors of vertex 1.
        [[0, 0.3], [1, 0.5], [3, 1.5], [4, 2]],  # Neighbors of vertex 2.
        [[2, 1.5], [4, 1.3], [5, 0.8]],  # Neighbors of vertex 3.
        [[2, 2], [3, 1.3]],  # Neighbors of vertex 4.
        [[0, 0.2], [3, 0.8]],  # Neighbors of vertex 5.
    ]

    graph = Graph(edges)
    print(graph.dijkstra(0))
