'''
--------------- CONNECTED COMPONENTS WITH DFS --------------------
-> Time Complexity - O(N) + O(2E) where, N - number of node, E - number of edges
-> This works for both directed and undirected graphs
-> Input Type -
    1. Adjancency list of a graph
    eg - [[1,2], [0], [0], [4], [3]]
-----------------------------------------------------------------
'''

def dfs_helper(graph, node, visited, traversal):
	visited[node] = 1 # mark as visited
	traversal.append(node)

	# traverse the neighbours
	for neighbour in graph[node]:
		if visited[neighbour]!=1:
			traversal = dfs_helper(graph, neighbour, visited, traversal)
	return traversal


def print_connected_components(graph):

    n = len(graph) # number of nodes in graph
    visited = [0 for i in range(n)] # mark each node as 0, it means the node is not visited
    components = [] # to store the connected components

    for node in range(n):
        if visited[node]==0:
            result = dfs_helper(graph, node, visited, [])
            components.append(result)

    print("The Connected Components are - ")
    for component in components:
        print(*component)
	 

# Your input code goes right here
def input():
    graph = []
    return graph

if __name__=='__main__':
    #graph = input()
    graph = [[1,2], [0], [0], [4], [3]]
    print_connected_components(graph)