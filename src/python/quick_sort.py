""" Implementaçao do algoritmo quick sort """


def swap(a_list, pos1, pos2):
    """ Troca a posição de dois itens em uma lista """
    temp = a_list[pos1]
    a_list[pos1] = a_list[pos2]
    a_list[pos2] = temp


def partition(a_list, start, end):
    """ Divide uma lista """
    pivot = a_list[start]
    while True:
        while a_list[start] < pivot:
            start = start + 1

        while a_list[end] > pivot:
            end = end - 1

        if start >= end:
            return end

        swap(a_list, start, end)

        start = start + 1
        end = end - 1


def quick_sort(a_list, start, end):
    """ Algoritmo de quick sort """
    if start < end:
        part = partition(a_list, start, end)
        quick_sort(a_list, start, part)
        quick_sort(a_list, part + 1, end)


if __name__ == "__main__":
    a = [9, 8, 5, 7, 6, 2, 4, 3, 1]
    print(a)
    quick_sort(a, 0, len(a) - 1)
    print(a)
