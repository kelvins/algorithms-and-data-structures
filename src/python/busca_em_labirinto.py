"""
Breadth-first and depth-first search in a maze with the goal of finding a path 
from the "start" point to the "goal" point.
Reference: Classic Computer Science Problems in Python
 
"""

import random
from collections import deque, namedtuple
from enum import Enum


class Cell(Enum):
    EMPTY = " "
    BLOCKED = "X"
    START = "S"
    GOAL = "G"
    PATH = "*"


MazeLocation = namedtuple("MazeLocation", ["row", "col"])


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
        """Randomly fill the maze."""
        for row in range(rows):
            for col in range(cols):
                if random.uniform(0, 1.0) < sparseness:
                    self._grid[row][col] = Cell.BLOCKED

    def __str__(self):
        return "\n".join(["|".join([c.value for c in r]) for r in self._grid])

    def goal_test(self, maze_location):
        return maze_location == self.goal

    def successors(self, ml):
        """Calculate possible locations to move to."""
        locations = list()
        if ml.row + 1 < self._rows and self._grid[ml.row + 1][ml.col] != Cell.BLOCKED:
            locations.append(MazeLocation(ml.row + 1, ml.col))
        if ml.row - 1 >= 0 and self._grid[ml.row - 1][ml.col] != Cell.BLOCKED:
            locations.append(MazeLocation(ml.row - 1, ml.col))
        if ml.col + 1 < self._cols and self._grid[ml.row][ml.col + 1] != Cell.BLOCKED:
            locations.append(MazeLocation(ml.row, ml.col + 1))
        if ml.col - 1 >= 0 and self._grid[ml.row][ml.col - 1] != Cell.BLOCKED:
            locations.append(MazeLocation(ml.row, ml.col - 1))
        return locations

    def mark(self, path):
        """Mark the path taken in the maze."""
        for maze_location in path:
            self._grid[maze_location.row][maze_location.col] = Cell.PATH
        self._grid[self.start.row][self.start.col] = Cell.START
        self._grid[self.goal.row][self.goal.col] = Cell.GOAL

    def clear(self, path):
        """Clear the marked path in the maze."""
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
    """Depth-first search algorithm."""
    # frontier represents the locations we have not visited yet
    frontier = Stack()
    frontier.push(Node(initial, None))
    # explored represents the locations that have already been visited
    explored = {initial}

    # Continue while there are locations to explore
    while not frontier.empty:
        current_node = frontier.pop()
        current_state = current_node.state

        # If we find the goal, return the current node
        if goal_test(current_state):
            return current_node

        # Check where we can go next
        for child in successors(current_state):
            # Ignore child nodes that have already been visited
            if child in explored:
                continue
            explored.add(child)
            frontier.push(Node(child, current_node))
    
    # We've gone through all locations and didn't reach the goal
    return None


def bfs(initial, goal_test, successors):
    """Breadth-first search algorithm."""
    # frontier represents the locations we have not visited yet
    frontier = Queue()
    frontier.push(Node(initial, None))
    # explored represents the locations that have already been visited
    explored = {initial}

    # Continue while there are locations to explore
    while not frontier.empty:
        current_node = frontier.pop()
        current_state = current_node.state

        # If we find the goal, return the current node
        if goal_test(current_state):
            return current_node

        # Check where we can go next
        for child in successors(current_state):
            # Ignore child nodes that have already been visited
            if child in explored:
                continue
            explored.add(child)
            frontier.push(Node(child, current_node))
    
    # We've gone through all locations and didn't reach the goal
    return None


def node_to_path(node):
    """Return the path found by the algorithm."""
    path = [node.state]
    while node.parent:
        node = node.parent
        path.append(node.state)
    path.reverse()
    return path


if __name__ == "__main__":
    maze = Maze()

    # Solution using depth-first search
    solution = dfs(maze.start, maze.goal_test, maze.successors)
    if solution is None:
        print("No solution found using depth-first search")
    else:
        path = node_to_path(solution)
        maze.mark(path)
        print("Solution using DFS:")
        print(maze)
        maze.clear(path)

    # Solution using breadth-first search
    solution = bfs(maze.start, maze.goal_test, maze.successors)
    if solution is None:
        print("No solution found using breath-first search")
    else:
        path = node_to_path(solution)
        maze.mark(path)
        print("Solution using BFS:")
        print(maze)
        maze.clear(path)
        