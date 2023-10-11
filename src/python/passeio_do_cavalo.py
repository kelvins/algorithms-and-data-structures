"""Implementation of the Knight's Tour algorithm"""

def is_acceptable(x, y):
    """
    Acceptable if it's within the board and the cell hasn't been visited yet.

    Returns True or False.
    """
    if 0 <= x < num and 0 <= y < num and board[x][y] == 0:
        return True
    else:
        return False

def try_move(i, x, y):
    """
    Attempt the i-th move at (x, y), 1 <= i <= n^2.
    """
    done = i > num_square
    k = 0
    while not done and k < 8:
        u = x + dx[k]  # Coordinates of the 8 possible knight moves
        v = y + dy[k]  # Coordinates of the 8 possible knight moves
        if is_acceptable(u, v):
            board[u][v] = i
            done = try_move(i + 1, u, v)
            if not done:
                board[u][v] = 0  # Unsuccessful move, revert it
        k += 1
    return done

def show_movement(x, y):
    board[x][y] = 1
    done = try_move(2, x, y)
    result = ""
    if done:
        for x in range(0, num):
            for y in range(0, num):
                if board[x][y] < 10:
                    result += "0" + str(board[x][y]) + " "
                else:
                    result += str(board[x][y]) + " "
            result += "\n"
        print(result)
    else:
        print("No possible tour available\n")

dx = [2, 1, -1, -2, -2, -1, 1, 2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

print("Enter the number of board positions: (e.g., 6) <= 10")
num = int(input())  # Number of board positions
print("Enter the x position where the knight should start: (e.g., 1) >= 0")
x = int(input())  # X position where the knight should start
print("Enter the y position where the knight should start: (e.g., 2) >= 0")
y = int(input())  # Y position where the knight should start
num_square = num * num  # Total number of cells on the board

print()

board = [[0] * num for _ in range(num)]  # Maximum 20x20 board
show_movement(x, y)
