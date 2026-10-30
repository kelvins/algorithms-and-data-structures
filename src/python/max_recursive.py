"""Exemplo de Máximo, utilizando recursão."""


def max_recursive(array, maximum, index):
    """Search o value maximum através usando recursão."""
    if array[index] > maximum:
        maximum = array[index]
    if index < len(array) - 1:
        maximum = max_recursive(array, maximum, index + 1)
    return maximum


if __name__ == "__main__":
    list = [19, 32, 43, 58, 12, 28, 98, 19, 12, 10]
    print(list)
    print(f"Max: {max_recursive(list, list[0], 0)}")
