#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
Given an integer array nums of unique elements, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

// Using Bit Manipulation
// 1) Traverse all subsets
// 2) Traverse all elements of nums
// 3) Check if jth bit is set in i
// It is like for 3 elements:
// 000, 001, 010, 011, 100, 101, 110, 111
// where 1 means that element is present in the subset
// Time: O(n * 2ⁿ)
// Space: O(1)
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int total = 1 << n; // 2ⁿ
    vector<vector<int>> ans(total);

    // Traverse all subsets
    for (int i = 0; i < total; i++) // 2ⁿ
    {
        // Traverse elements of nums
        for (int j = 0; j < n; j++) // n
        {
            // Check if jth bit is set in i
            if ((1 << j) & i)
            {
                ans[i].push_back(nums[j]);
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);

    cout << "Subsets are: \n";
    for (auto v : ans)
    {
        cout << "[ ";
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << "]\n";
    }

    return 0;
}
