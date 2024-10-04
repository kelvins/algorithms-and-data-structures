def cocktail_shaker_sort(arr):
    n = len(arr)
    swapped = True
    start = 0
    end = n - 1

    while swapped:
        # reset the swapped flag on entering the loop
        swapped = False

        # Traverse the list from left to right
        for i in range(start, end):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True

        # If no elements were swapped, the list is already sorted
        if not swapped:
            break

        # Reset the swapped flag for the next stage
        swapped = False

        # Move the end point back by one
        end -= 1

        # Traverse the list from right to left
        for i in range(end - 1, start - 1, -1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True

        # Move the start point forward by one
        start += 1

# Example usage
arr = [5, 1, 4, 2, 8, 0, 2]
cocktail_shaker_sort(arr)
print("Sorted array:", arr)
