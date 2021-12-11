# Grafos - Algoritmo de Floyd-Warshall em Python
# Alexandre Lima - 2021
# https://github.com/alelimasilva

from math import inf


def gerar_matriz(n_linhas, n_colunas):
    return [[0] * n_colunas for _ in range(n_linhas)]


def imprime(matriz, vertices):
    print(' ', end='')
    for i in range(vertices):
        print("  ", i + 1, end='')
    print('')
    for i in range(vertices):
        print(i + 1, matriz[i])


def floyd_warshall(matriz, vertices):
    dist = gerar_matriz(vertices, vertices)
    # inicializando a matriz com infinito nas diagonais e as distancias das arestas
    for i in range(vertices):
        for j in range(vertices):
            if i != j:
                if matriz[i][j] != 0:
                    dist[i][j] = matriz[i][j]
                else:
                    dist[i][j] = inf
            else:
                dist[i][i] = inf
    # Floyd-Warshal
    for k in range(vertices):
        for i in range(vertices):
            for j in range(vertices):
                Dist = inf
                if dist[i][k] != inf or dist[k][j] != inf:
                    Dist = dist[i][k] + dist[k][j]

                if i != j and Dist != inf and Dist < dist[i][j]:
                    dist[i][j] = Dist
    # printando o resultado
    print('Matriz de distâncias')
    imprime(dist, vertices)


def main():
    grafo = [[0, 3, 4, 0], [0, 0, 0, 5], [0, 0, 0, 3], [8, 0, 0, 0]]
    vertices = 4
    floyd_warshall(grafo, vertices)


if __name__ == "__main__":
    main()
