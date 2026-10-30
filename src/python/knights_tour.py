"""Implement the knight's tour algorithm."""


def is_valid_move(x, y):
    """
    Valid if the position is within the board and the square has not yet been
    visited

    Return True or False
    """
    if x >= 0 and x <= num - 1 and y >= 0 and y <= num - 1 and board[x][y] == 0:
        return True
    else:
        return False


def try_move(i, x, y):
    """
    Try the i-th move at (x, y), where 1 <= i <= n^2
    """
    done = i > board_square_count  # True ou False
    k = 0
    while not done and k < 8:
        u = x + dx[k]  # Coordinates of the knight's eight possible moves
        v = y + dy[k]  # Coordinates of the knight's eight possible moves
        if is_valid_move(u, v):
            board[u][v] = i
            done = try_move(i + 1, u, v)  # Try another move
            if not done:
                board[u][v] = 0  # If unsuccessful, discard the move
        k += 1  # Move to the next possible move
    return done


def print_solution(x, y):
    board[x][y] = 1
    done = try_move(2, x, y)
    string = ""
    if done:
        for x in range(0, num):
            for y in range(0, num):
                if board[x][y] < 10:
                    string += "0" + str(board[x][y]) + " "
                else:
                    string += str(board[x][y]) + " "
            string += "\n"
        print(string)
    else:
        print("No knight's tour is possible.\n")


dx = [2, 1, -1, -2, -2, -1, 1, 2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

print("Enter the board size (e.g. 6), at most 10:")
num = int(input())  # Board size
print("Enter the knight's starting x position (e.g. 1), at least 0:")
x = int(input())  # Board size
print("Enter the knight's starting y position (e.g. 2), at least 0:")
y = int(input())  # Board size
board_square_count = num * num  # Total number of squares

print()

board = [[], [], [], [], [], [], [], [], [], []]  # Board supports up to 20 x 20.
for x in range(0, num):
    for y in range(0, num):
        board[x].append(0)
# print board
print_solution(x, y)
