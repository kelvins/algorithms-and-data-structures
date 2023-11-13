/*
    Recursive Towers of Hanoi Solution

    Problem Description: (from wikipedia)
    The Tower of Hanoi is a mathematical game or puzzle consisting of three rods and a number of disks of various diameters,
    which can slide onto any rod.

    The puzzle begins with the disks stacked on one rod in order of decreasing size, the smallest at the top,
    thus approximating a conical shape.

    The objective of the puzzle is to move the entire stack to the last rod, obeying the following rules:

    Only one disk may be moved at a time.

    Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.

    No disk may be placed on top of a disk that is smaller than it.

    With 3 disks, the puzzle can be solved in 7 moves.

    The minimal number of moves required to solve a Tower of Hanoi puzzle is 2^n − 1, where n is the number of disks.

*/

#include <iostream>
using std::cout;

size_t solve_tower(int n, char first, char second, char third)
{

    // recursive base case
    if (n == 1)
    {
        cout << "Move disk 1 from " << first << " to " << third << "\n";
        return 1;
    }

    // move n-1 disks from first to other using second as a placeholder
    size_t num_moves = solve_tower(n - 1, first, third, second);

    // move the nth disk from first to second
    cout << "Move disk " << n << " from " << first << " to " << third << "\n";

    // move the n-1 disks from third to second using first as an placeholder
    num_moves += solve_tower(n - 1, second, first, third);

    // return the total moves plus 1
    return num_moves + 1;
}

int main()
{

    // names of rods
    char a = 'A';
    char b = 'B';
    char c = 'C';

    // number of disks to move in puzzle
    size_t num_disk = 3;

    // find the total number of moves needed to solve
    size_t num_moves = solve_tower(num_disk, a, b, c);

    // output result
    cout << "Total moves needed to solve: " << num_moves;
    return 0;
}
