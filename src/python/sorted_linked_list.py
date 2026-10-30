"""Dynamic sorted sequential list."""

import random

list = []


def insert_list(key, list):
    """Insert a key into the list."""
    list.append(key)
    i, p = 0, 0
    while list[i] < key:
        i += 1
    p = len(list) - 2
    while p >= i:
        list[p + 1] = list[p]
        p -= 1
    list[i] = key


def search_sentinel(key, list):
    """Search the list using a sentinel."""
    list.append(key)
    i = 0
    while list[i] != key:
        i += 1
    if i == len(list) - 1:
        list.pop()
        return -1
    list.pop()
    return i


def delete_value(key, list):
    """Delete a key from the list."""
    position = search_sentinel(key, list)
    if position >= 0:
        list.pop(position)
        return True
    return False


def print_list(list):
    """Print the list."""
    print(list)


for _ in range(0, 50):
    insert_list(random.randint(10, 99), list)

print("Value at position: " + str(search_sentinel(25, list)))

print_list(list)
delete_value(10, list)
print_list(list)
