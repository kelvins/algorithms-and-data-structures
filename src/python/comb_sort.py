#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#----------------------------------------------------------------------------
# Created By  : octaviolage
# Created Date: 2022-05-15
# version ='1.0'
# -------------------------------
def comb_sort(arr: list) -> list:
    """
    Implementação de um algoritmo de ordenação combinada.
    """
    gap = len(arr)
    shrink = 1.3
    swapped = True
    while gap > 1 or swapped:
        gap = int(gap / shrink)
        if gap < 1:
            gap = 1
        swapped = False
        for i in range(len(arr) - gap):
            if arr[i] > arr[i + gap]:
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                swapped = True
    return arr

if __name__ == '__main__':
    from random import randint
    my_list = [randint(0, 100) for _ in range(10)]
    print(f'Lista: {my_list}')
    print(f'Ordenada: {comb_sort(my_list)}')