"""
Busca em largura e em profundidade em um labirinto com o objetivo
de encontrar um caminho do ponto "start" ao ponto "goal"
Referencia: Problemas Classicos de Ciencia da Computacao com Python
"""

import random
from collections import deque, namedtuple
from enum import Enum


class Cell(Enum):
    EMPTY = ' '
    BLOCKED = 'X'
    START = 'S'
    GOAL = 'G'
    PATH = '*'


MazeLocation = namedtuple('MazeLocation', ['row', 'col'])


class Maze:
    def __init__(
        self,
        rows=10,
        cols=10,
        sparseness=0.2,
        start=MazeLocation(0, 0),
        goal=MazeLocation(9, 9),
    ):
        self._rows = rows
        self._cols = cols
        self.start = start
        self.goal = goal
        self._grid = [[Cell.EMPTY for _ in range(cols)] for _ in range(rows)]
        self._randomly_fill(rows, cols, sparseness)
        self._grid[start.row][start.col] = Cell.START
        self._grid[goal.row][goal.col] = Cell.GOAL

    def _randomly_fill(self, rows, cols, sparseness):
        """Preenche o labirinto de forma randomica."""
        for row in range(rows):
            for col in range(cols):
                if random.uniform(0, 1.0) < sparseness:
                    self._grid[row][col] = Cell.BLOCKED

    def __str__(self):
        return '\n'.join(['|'.join([c.value for c in r]) for r in self._grid])

    def goal_test(self, maze_location):
        return maze_location == self.goal

    def successors(self, ml):
        """Calcula as possiveis localizacoes onde eh possivel se mover."""
        locations = list()
        if (
            ml.row + 1 < self._rows
            and self._grid[ml.row + 1][ml.col] != Cell.BLOCKED
        ):
            locations.append(MazeLocation(ml.row + 1, ml.col))
        if ml.row - 1 >= 0 and self._grid[ml.row - 1][ml.col] != Cell.BLOCKED:
            locations.append(MazeLocation(ml.row - 1, ml.col))
        if (
            ml.col + 1 < self._cols
            and self._grid[ml.row][ml.col + 1] != Cell.BLOCKED
        ):
            locations.append(MazeLocation(ml.row, ml.col + 1))
        if ml.col - 1 >= 0 and self._grid[ml.row][ml.col - 1] != Cell.BLOCKED:
            locations.append(MazeLocation(ml.row, ml.col - 1))
        return locations

    def mark(self, path):
        """Marca o caminho andado no labirinto."""
        for maze_location in path:
            self._grid[maze_location.row][maze_location.col] = Cell.PATH
        self._grid[self.start.row][self.start.col] = Cell.START
        self._grid[self.goal.row][self.goal.col] = Cell.GOAL

    def clear(self, path):
        """Limpa o caminho marcado no labirinto."""
        for maze_location in path:
            self._grid[maze_location.row][maze_location.col] = Cell.EMPTY
        self._grid[self.start.row][self.start.col] = Cell.START
        self._grid[self.goal.row][self.goal.col] = Cell.GOAL


class Stack:
    def __init__(self):
        self._data = list()

    @property
    def empty(self):
        return not self._data

    def push(self, value):
        self._data.append(value)

    def pop(self):
        return self._data.pop()

    def __repr__(self):
        return repr(self._data)


class Queue:
    def __init__(self):
        self._data = deque()

    @property
    def empty(self):
        return not self._data

    def push(self, value):
        self._data.append(value)

    def pop(self):
        return self._data.popleft()

    def __repr__(self):
        return repr(self._data)


class Node:
    def __init__(self, state, parent):
        self.state = state
        self.parent = parent


def dfs(initial, goal_test, successors):
    """Algoritmo de busca em profundidade."""
    # frontier representa os lugares que ainda nao visitamos
    frontier = Stack()
    frontier.push(Node(initial, None))
    # explored representa os lugares que ja foram visitados
    explored = {initial}

    # continua enquanto houver lugares para explorar
    while not frontier.empty:
        current_node = frontier.pop()
        current_state = current_node.state

        # se encontrar o objetivo retorna o no atual
        if goal_test(current_state):
            return current_node

        # verifica para onde podemos ir em seguida
        for child in successors(current_state):
            # ignora os nos filhos que ja foram visitados
            if child in explored:
                continue
            explored.add(child)
            frontier.push(Node(child, current_node))
    # passamos por todos os lugares e nao atingimos o objetivo
    return None


def bfs(initial, goal_test, successors):
    """Algoritmo de busca em largura."""
    # frontier representa os lugares que ainda nao visitamos
    frontier = Queue()
    frontier.push(Node(initial, None))
    # explored representa os lugares que ja foram visitados
    explored = {initial}

    # continua enquanto houver lugares para explorar
    while not frontier.empty:
        current_node = frontier.pop()
        current_state = current_node.state

        # se encontrar o objetivo retorna o no atual
        if goal_test(current_state):
            return current_node

        # verifica para onde podemos ir em seguida
        for child in successors(current_state):
            # ignora os nos filhos que ja foram visitados
            if child in explored:
                continue
            explored.add(child)
            frontier.push(Node(child, current_node))
    # passamos por todos os lugares e nao atingimos o objetivo
    return None


def node_to_path(node):
    """Retorna o caminho encontrado pelo algoritmo."""
    path = [node.state]
    while node.parent:
        node = node.parent
        path.append(node.state)
    path.reverse()
    return path


if __name__ == '__main__':
    maze = Maze()

    # Solucao utilizando busca em profundidade
    solution = dfs(maze.start, maze.goal_test, maze.successors)
    if solution is None:
        print('No solution found using depth-first search')
    else:
        path = node_to_path(solution)
        maze.mark(path)
        print('Solution using DFS:')
        print(maze)
        maze.clear(path)

    # Solucao utilizando busca em largura
    solution = bfs(maze.start, maze.goal_test, maze.successors)
    if solution is None:
        print('No solution found using breath-first search')
    else:
        path = node_to_path(solution)
        maze.mark(path)
        print('Solution using BFS:')
        print(maze)
        maze.clear(path)
