#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int value, vector<int> &vec, int leftIndex, int rightIndex)
{
    int mid = (leftIndex + rightIndex) / 2;

    if (leftIndex <= rightIndex)
    {
        if (value > vec[mid])
        {
            leftIndex = mid + 1;
            return binarySearch(value, vec, leftIndex, rightIndex);
        }
        else if (value < vec[mid])
        {
            rightIndex = mid - 1;
            return binarySearch(value, vec, leftIndex, rightIndex);
        }
        else
        {
            return mid;
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> vec;
 
    for (int index = 1; index <= 50; index++)
    {
        vec.push_back(index);
    }

    int value = 45;

    int index = binarySearch(value, vec, 0, vec.size());

    if (index >= 0)
    {
        cout << "Value " << to_string(value) << " found at position " << to_string(index) << endl;
    }
    else
    {
        cout << "Could not find the value " << to_string(value) << endl;
    }
}