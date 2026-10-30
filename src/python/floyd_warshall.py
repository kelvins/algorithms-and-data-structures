# Graphs - Floyd-Warshall algorithm in Python
# Alexandre Lima - 2021
# https://github.com/alelimasilva

from math import inf


def generate_matrix(num_rows, num_columns):
    return [[0] * num_columns for _ in range(num_rows)]


def print_matrix(matrix, vertices):
    print(" ", end="")
    for i in range(vertices):
        print("  ", i + 1, end="")
    print("")
    for i in range(vertices):
        print(i + 1, matrix[i])


def floyd_warshall(matrix, vertices):
    dist = generate_matrix(vertices, vertices)
    # Initialize the matrix with infinity on the diagonal and edge distances
    for i in range(vertices):
        for j in range(vertices):
            if i != j:
                if matrix[i][j] != 0:
                    dist[i][j] = matrix[i][j]
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
    # Print the result
    print("Distance matrix")
    print_matrix(dist, vertices)


def main():
    graph = [[0, 3, 4, 0], [0, 0, 0, 5], [0, 0, 0, 3], [8, 0, 0, 0]]
    vertices = 4
    floyd_warshall(graph, vertices)


if __name__ == "__main__":
    main()
