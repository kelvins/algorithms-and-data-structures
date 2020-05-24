""" Implementacao do algoritmo shell sort """


def shell_sort(a_list):
    """
    Algoritmo shell sort.

    Argumentos:
        a_list: list. Uma lista nao ordenada
    """
    sublist_count = len(a_list) // 2
    while sublist_count > 0:
        for start_position in range(sublist_count):
            gap_insertion_sort(a_list, start_position, sublist_count)

        sublist_count = sublist_count // 2


def gap_insertion_sort(a_list, start, gap):
    """
    Algoritmo gap insertion sort.
    """
    for i in range(start + gap, len(a_list), gap):
        current_value = a_list[i]
        position = i
        while position >= gap and a_list[position - gap] > current_value:
            a_list[position] = a_list[position - gap]
            position = position - gap

        a_list[position] = current_value


some_list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
shell_sort(some_list)
print(some_list)


def shell(seq):
    """
    Algoritmo de ordenacao shell

    Argumentos:
        seq: list. lista nao ordenada
    """
    inc = len(seq) // 2
    while inc:
        for i, element in enumerate(seq):
            while i >= inc and seq[i - inc] > element:
                seq[i] = seq[i - inc]
                i -= inc
            seq[i] = element
        inc = 1 if inc == 2 else int(inc * 5.0 / 11)


data = [22, 7, 2, -5, 8, 4]
shell(data)
print(data)  # [-5, 2, 4, 7, 8, 22]
