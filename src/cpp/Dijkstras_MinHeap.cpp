/**
 * Dijkstras_MinHeap.cpp
 *
 * This file implements Dijkstra's algorithm using a min-heap (priority queue).
 * The algorithm finds the shortest paths from the source vertex to all other vertices in a weighted graph.
 *
 * Functions:
 * - void dijkstra(const unordered_map<int, unordered_map<int, int>>& graph, int start_vertex)
 *      - graph: An adjacency list representation of the graph.
 *          - key: vertex
 *          - value: unordered_map of connected vertices and their edge weights
 *      - start_vertex: The starting vertex for Dijkstra's algorithm.
 *
 * Example Usage:
 * Uncomment the main function to run a sample test case.
 * The sample graph used in the main function is represented as an adjacency list.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

// A structure to represent a node in the priority queue
struct Node {
    int vertex;
    int distance;
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

void dijkstra(const unordered_map<int, unordered_map<int, int>>& graph, int start_vertex) {
    // Initialize distances and predecessors
    unordered_map<int, int> dist;
    unordered_map<int, int> pred;
    for (const auto& pair : graph) {
        dist[pair.first] = numeric_limits<int>::max();
        pred[pair.first] = -1;
    }
    dist[start_vertex] = 0;

    // Priority queue to store vertices and their distances
    priority_queue<Node, vector<Node>, greater<Node>> priority_queue;
    priority_queue.push({ start_vertex, 0 });

    while (!priority_queue.empty()) {
        Node current = priority_queue.top();
        priority_queue.pop();

        // If this distance is not updated, continue
        if (current.distance > dist[current.vertex]) {
            continue;
        }

        // Visit each neighbor of the current vertex
        for (const auto& neighbor_pair : graph.at(current.vertex)) {
            int neighbor = neighbor_pair.first;
            int weight = neighbor_pair.second;
            int distance = current.distance + weight;

            // If a shorter path to the neighbor is found
            if (distance < dist[neighbor]) {
                dist[neighbor] = distance;
                pred[neighbor] = current.vertex;
                priority_queue.push({ neighbor, distance });
            }
        }
    }

    // Print distances and predecessors
    cout << "Distances: \n";
    for (const auto& pair : dist) {
        cout << "Vertex " << pair.first << ": " << pair.second << endl;
    }
    cout << "\nPredecessors: \n";
    for (const auto& pair : pred) {
        cout << "Vertex " << pair.first << ": " << pair.second << endl;
    }
}

// Uncomment the following main function to run a sample test case

int main() {
    // Example graph represented as an adjacency list
    unordered_map<int, unordered_map<int, int>> graph = {
        {0, {{1, 1}, {2, 4}}},
        {1, {{0, 1}, {2, 2}, {3, 5}}},
        {2, {{0, 4}, {1, 2}, {3, 1}}},
        {3, {{1, 5}, {2, 1}}}
    };

    // Running Dijkstra's algorithm from vertex 0
    dijkstra(graph, 0);

    return 0;
}
