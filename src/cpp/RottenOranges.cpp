#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
Given an m x n grid, where each cell has the following values:
2  –  Rotten orange
1  –  Fresh orange
0  –  Empty cell

Every minute, if a Fresh orange is adjacent to a Rotten Orange in 4-direction
(upward, downwards, right, and left) it becomes Rotten.

Return the minimum number of minutes required such that
none of the cells has a Fresh Orange.
If it's not possible, return -1.
*/

// Approach: BFS

bool isValid(int nx, int ny, int m, int n)
{
    return (0 <= nx && nx < m) &&
           (0 <= ny && ny < n);
}

// Time: O(mn) x 4
// Space: O(mn)
int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    int total = 0; // fresh + rotten oranges
    int count = 0; // rotten oranges
    int mins = 0;  // minutes elapsed

    queue<pair<int, int>> rotten; // {i, j}: position of rotten orange

    // Count the fresh & rotten oranges, push rotten oranges into queue
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 0) // Rotten or Fresh orange
                total++;
            if (grid[i][j] == 2)     // Rotten
                rotten.push({i, j}); // Push position of rotten orange
        }
    }

    int dx[] = {0, 0, -1, 1}; // 4-directions (x-axis)
    int dy[] = {-1, 1, 0, 0}; // 4-directions (y-axis)

    while (!rotten.empty())
    {
        int size = rotten.size(); // rotten oranges in current minute
        count += size;            // add to total rotten oranges

        while (size--) // Each rotten orange in current minute
        {
            // Pop the front rotten orange
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            // Check for fresh oranges in 4-directions
            for (int i = 0; i < 4; i++)
            {
                // New coordinates
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Valid, fresh orange
                if (isValid(nx, ny, m, n) && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;      // make it rotten
                    rotten.push({nx, ny}); // push it into queue
                }
            }
        }

        if (!rotten.empty()) // if there are more rotten oranges
            mins++;
    }

    if (total != count) // fresh oranges left
        return -1;

    return mins;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1},
                                {1, 1, 0},
                                {0, 1, 1}};

    cout << orangesRotting(grid) << endl; // 4

    return 0;
}
