from itertools import permutations

def calculate_total_distance(path, distances):
    """
    Calculate the total distance of a path through cities.

    Args:
        path (list of int): A list representing the order of cities to visit.
        distances (list of lists of int): A distance matrix between cities.

    Returns:
        int: The total distance of the path.

    Example:
    >>> distances = [[0, 2, 9, 10], [1, 0, 6, 4], [15, 7, 0, 8], [6, 3, 12, 0]]
    >>> calculate_total_distance([0, 1, 2, 3, 0], distances)
    21
    """
    total_distance = 0
    for i in range(len(path) - 1):
        total_distance += distances[path[i]][path[i + 1]]
    total_distance += distances[path[-1]][path[0]]
    return total_distance

def traveling_salesman_bruteforce(distances):
    """
    Find the shortest path through cities using brute force.

    Args:
        distances (list of lists of int): A distance matrix between cities.

    Returns:
        tuple: A tuple containing the shortest path (list of int) and the shortest distance (int).

    Example:
    >>> distances = [[0, 2, 9, 10], [1, 0, 6, 4], [15, 7, 0, 8], [6, 3, 12, 0]]
    >>> traveling_salesman_bruteforce(distances)
    ([0, 1, 3, 2], 21)
    """
    num_cities = len(distances)
    all_cities = list(range(num_cities))
    shortest_path = None
    shortest_distance = float('inf')

    for path in permutations(all_cities):
        distance = calculate_total_distance(path, distances)
        if distance < shortest_distance:
            shortest_distance = distance
            shortest_path = path

    return shortest_path, shortest_distance

def create_distance_matrix(num_cities):
    """
    Create a distance matrix for a given number of cities.

    Args:
        num_cities (int): The number of cities.

    Returns:
        list of lists of int: A distance matrix between cities.

    Example:
    >>> create_distance_matrix(4)
    [[0, 2, 9, 10], [2, 0, 6, 4], [9, 6, 0, 8], [10, 4, 8, 0]]
    """
    distances = []
    for i in range(num_cities):
        row = []
        for j in range(num_cities):
            if i == j:
                row.append(0)
            elif j > i:
                distance = int(input(f"Enter distance between City {i + 1} and City {j + 1}: "))
                row.append(distance)
            else:
                row.append(distances[j][i])
        distances.append(row)
    return distances

def print_distance_matrix(distances):
    """
    Print the distance matrix.

    Args:
        distances (list of lists of int): A distance matrix between cities.

    Example:
    >>> distances = [[0, 2, 9, 10], [1, 0, 6, 4], [15, 7, 0, 8], [6, 3, 12, 0]]
    >>> print_distance_matrix(distances)
    Distance Matrix:
    [0, 2, 9, 10]
    [2, 0, 6, 4]
    [9, 6, 0, 8]
    [10, 4, 8, 0]
    """
    print("Distance Matrix:")
    for row in distances:
        print(row)

def print_city_path(path):
    """
    Print the shortest path through cities.

    Args:
        path (list of int): A list representing the order of cities to visit.

    Example:
    >>> print_city_path([0, 1, 3, 2])
    Shortest Path: City 1 -> City 2 -> City 4 -> City 3
    """
    city_path = [f"City {city + 1}" for city in path]
    print("Shortest Path:", " -> ".join(city_path))

def main_menu():
    """
    Display a menu for the traveling salesman problem and handle user input.

    Example:
    >>> # This function interacts with the user, so no specific doctests are provided.
    >>> # You can run this function manually to test the menu functionality.
    >>> main_menu()
    """
    while True:
        print("\nMenu:")
        print("1. Create a distance matrix")
        print("2. Find the shortest path")
        print("3. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            num_cities = int(input("Enter the number of cities: "))
            distances = create_distance_matrix(num_cities)
            print_distance_matrix(distances)
        elif choice == '2':
            if 'distances' in locals():
                shortest_path, shortest_distance = traveling_salesman_bruteforce(distances)
                print_city_path(shortest_path)
                print("Shortest Distance:", shortest_distance)
            else:
                print("Please create a distance matrix first.")
        elif choice == '3':
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main_menu()
