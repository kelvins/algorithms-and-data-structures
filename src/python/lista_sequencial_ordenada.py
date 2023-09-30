""" Lista Sequencial Dinamica e Ordenada """
"""Sequential Dynamic and Ordered List"""

import random

my_list = []

def insert_into_list(key, my_list):
    """
    Inserts the key into the list
    """
    my_list.append(key)
    i, p = 0, 0
    while my_list[i] < key:
        i += 1
    p = len(my_list) - 2
    while p >= i:
        my_list[p + 1] = my_list[p]
        p -= 1
    my_list[i] = key

def sentinel_search(key, my_list):
    """Sentinel search algorithm"""
    my_list.append(key)
    i = 0
    while my_list[i] != key:
        i += 1
    if i == len(my_list) - 1:
        my_list.pop()
        return -1
    my_list.pop()
    return i

def delete_value(key, my_list):
    """Deletes a key from the list"""
    position = sentinel_search(key, my_list)
    if position >= 0:
        my_list.pop(position)
        return True
    return False

def display_list(my_list):
    """Prints the list"""
    print(my_list)

for _ in range(0, 50):
    insert_into_list(random.randint(10, 99), my_list)

print("Value at position: " + str(sentinel_search(25, my_list)))

display_list(my_list)
delete_value(10, my_list)
display_list(my_list)
