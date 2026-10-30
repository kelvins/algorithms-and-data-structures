"""Implement the Tower of Hanoi algorithm."""


def hanoi(source_peg, target_peg, helper_peg, disk_count):
    """
    Show the recursive steps for solving the Tower of Hanoi.
    Args: source peg, target peg, helper peg, and number of disks.
    """
    if disk_count == 1:
        print("Move from {} to {}".format(source_peg, target_peg))
    else:
        hanoi(source_peg, helper_peg, target_peg, disk_count - 1)
        hanoi(source_peg, target_peg, helper_peg, 1)
        hanoi(helper_peg, target_peg, source_peg, disk_count - 1)


if __name__ == "__main__":
    hanoi(0, 2, 1, 3)
