# Hamiltonian Cycle is a path in a graph that visits each vertex exactly once and returns to the starting vertex.

# (A)---------------(B)-------------(E)---------------(F)
#  |                 |               |                 |
#  |                 |               |                 |
#  |                 |               |                 | 
# (C)---------------(D)---------------                 |
#                    |                                 |
#                    -----------------------------------

# 6 Vertices
# 9 Edges

class Vertex:
    def __init__(self, id):
        self.id = id
        self.neighbors = []
        self.visited = False

def connect_vertices(v1, v2):
    v1.neighbors.append(v2)
    v2.neighbors.append(v1)

def hamiltonian_cycle_helper(graph, path, pos):
    # If all vertices are included in the path
    if pos == len(graph):
        # Check if last vertex is connected to first vertex
        if path[-1] in path[0].neighbors:
            return True
        return False
    
    # Try different vertices as next candidate
    for vertex in graph:
        if can_add_to_path(vertex, path, pos):
            path[pos] = vertex
            vertex.visited = True
            
            if hamiltonian_cycle_helper(graph, path, pos + 1):
                return True
                
            # Backtrack
            vertex.visited = False
            path[pos] = None
    
    return False

def can_add_to_path(vertex, path, pos):
    # If vertex is already visited, skip it
    if vertex.visited:
        return False
    
    # For first vertex, any unvisited vertex is valid
    if pos == 0:
        return True
    
    # Check if current vertex is connected to the previous vertex in path
    if vertex not in path[pos-1].neighbors:
        return False
        
    return True

def find_hamiltonian_cycle(graph):
    # Initialize the path
    path = [None] * len(graph)
    
    # Reset all vertices to unvisited
    for vertex in graph:
        vertex.visited = False
    
    if hamiltonian_cycle_helper(graph, path, 0):
        # Add the first vertex at the end to complete the cycle
        return path + [path[0]]
    return None

def main():
    # Create graph vertices
    graph = [
        Vertex('A'),  # 0
        Vertex('B'),  # 1
        Vertex('C'),  # 2
        Vertex('D'),  # 3
        Vertex('E'),  # 4
        Vertex('F')   # 5
    ]
    
    # Connect vertices according to the graph diagram
    connect_vertices(graph[0], graph[1])  # A - B
    connect_vertices(graph[0], graph[2])  # A - C
    connect_vertices(graph[1], graph[3])  # B - D
    connect_vertices(graph[2], graph[3])  # C - D
    connect_vertices(graph[1], graph[4])  # B - E
    connect_vertices(graph[3], graph[4])  # D - E
    connect_vertices(graph[4], graph[5])  # E - F
    connect_vertices(graph[3], graph[5])  # D - F
    connect_vertices(graph[1], graph[5])  # B - F

    # Find Hamiltonian cycle
    cycle = find_hamiltonian_cycle(graph)
    
    if cycle:
        print("Hamiltonian Cycle found:")
        print(" -> ".join(vertex.id for vertex in cycle))
    else:
        print("No Hamiltonian Cycle exists")

if __name__ == "__main__":
    main()