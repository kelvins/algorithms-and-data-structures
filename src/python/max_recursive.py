"""Exemplo de Máximo, utilizando recursão."""


def max_recursivo(array, maximo, index):
    """Search o value máximo através usando recursão."""
    if array[index] > maximo:
        maximo = array[index]
    if index < len(array) - 1:
        maximo = max_recursivo(array, maximo, index + 1)
    return maximo


if __name__ == "__main__":
    list = [19, 32, 43, 58, 12, 28, 98, 19, 12, 10]
    print(list)
    print(f"Max: {max_recursivo(list, list[0], 0)}")
