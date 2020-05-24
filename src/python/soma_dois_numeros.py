"""
Problem
Given an array/list A of n numbers and another number x, determines
if exists two elements in A whose sum is exactly x

Works only for different values
"""


def solution1(values, expected):
    """
    determines if exists two elements in
    values whose sum is exactly expected
    """
    dic = {}
    for index, value in enumerate(values):
        dic[value] = index
        diff = expected - value
        if diff not in dic:
            continue
        if dic[diff] != index:
            return True
    return False


# Works with repeated values
def solution2(values, expected):
    """
    determines if exists two elements in
    values whose sum is exactly expected
    """
    dic = {}
    for index, value in enumerate(values):
        diff = expected - value
        if diff not in dic:
            dic[value] = index
            continue
        return True
    return False


if __name__ == "__main__":
    values = [42, 5, 9, 9, 16, 16, 13]

    print("Solution 1")

    print("Should be TRUE")
    print(solution1(values, 14))
    print(solution1(values, 25))
    print(solution1(values, 47))
    print(solution1(values, 58))
    print(solution1(values, 51))
    print(solution1(values, 21))
    print(solution1(values, 18))

    print("Should be FALSE")
    print(solution1(values, 32))
    print(solution1(values, 9))
    print(solution1(values, 59))
    print(solution2(values, 5))
    print(solution2(values, 10))
    print(solution2(values, 100))

    print("Solution 2")

    print("Should be TRUE")
    print(solution2(values, 14))
    print(solution2(values, 25))
    print(solution2(values, 47))
    print(solution2(values, 58))
    print(solution2(values, 32))
    print(solution2(values, 18))
    print(solution1(values, 51))
    print(solution1(values, 21))

    print("Should be FALSE")
    print(solution2(values, 10))
    print(solution2(values, 9))
    print(solution2(values, 59))
    print(solution2(values, 5))
    print(solution2(values, 100))
