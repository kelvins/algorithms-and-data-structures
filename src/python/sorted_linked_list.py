"""Dynamic sorted sequential list."""

import random

values = []


def insert_list(key, values):
    """Insert a key into the list."""
    values.append(key)
    i, p = 0, 0
    while values[i] < key:
        i += 1
    p = len(values) - 2
    while p >= i:
        values[p + 1] = values[p]
        p -= 1
    values[i] = key


def search_sentinel(key, values):
    """Search the list using a sentinel."""
    values.append(key)
    i = 0
    while values[i] != key:
        i += 1
    if i == len(values) - 1:
        values.pop()
        return -1
    values.pop()
    return i


def delete_value(key, values):
    """Delete a key from the list."""
    position = search_sentinel(key, values)
    if position >= 0:
        values.pop(position)
        return True
    return False


def print_list(values):
    """Print the list."""
    print(values)


for _ in range(0, 50):
    insert_list(random.randint(10, 99), values)

print("Value at position: " + str(search_sentinel(25, values)))

print_list(values)
delete_value(10, values)
print_list(values)
