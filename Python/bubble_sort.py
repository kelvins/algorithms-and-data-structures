
def bubble_sort(data, size):
    swap = False
    for x in range(0, size-1):
        if data[x] > data[x+1]:
            data[x], data[x+1] = data[x+1], data[x]
            swap = True
    if swap:
        bubble_sort(data, size-1)


if __name__ == '__main__':
    data = [2, 9, 8, 0, 1, 3, 5, 4, 6, 7]
    print(data)
    bubble_sort(data, len(data))
    print(data)
