use std::collections::BinaryHeap;
use std::collections::HashMap;
use std::collections::HashSet;

const INF: i32 = i32::MAX;

#[derive(Debug, PartialEq, Eq, Hash, Clone, Copy)]
struct Edge {
    target: usize,
    weight: i32,
}

#[derive(Debug, PartialEq, Eq, Hash, Clone)]
struct Graph {
    nodes: usize,
    edges: Vec<Vec<Edge>>,
}

impl Graph {
    // Constructor to create a new graph with a given number of nodes.
    fn new(nodes: usize) -> Self {
        Graph {
            nodes,
            edges: vec![vec![]; nodes],
        }
    }

    // Add an edge to the graph from 'from' node to 'to' node with a given weight.
    fn add_edge(&mut self, from: usize, to: usize, weight: i32) {
        self.edges[from].push(Edge { target: to, weight });
    }

    // Find the shortest path from a specified starting node using Dijkstra's algorithm.
    fn shortest_path(&self, start: usize) -> HashMap<usize, i32> {
        let mut distance: HashMap<usize, i32> = (0..self.nodes).map(|i| (i, INF)).collect();
        let mut visited: HashSet<usize> = HashSet::new();

        // Set the distance to the starting node to 0 and initialize a priority queue.
        distance.insert(start, 0);
        let mut min_heap: BinaryHeap<(i32, usize)> = BinaryHeap::new();
        min_heap.push((0, start));

        while let Some((_dist, node)) = min_heap.pop() {
            if visited.contains(&node) {
                continue;
            }

            visited.insert(node);

            // Explore neighboring nodes and update distances if a shorter path is found.
            for edge in &self.edges[node] {
                let new_dist = distance[&node] + edge.weight;
                if new_dist < distance[&edge.target] {
                    distance.insert(edge.target, new_dist);
                    min_heap.push((new_dist, edge.target));
                }
            }
        }

        distance
    }
}

fn main() {
    // Create a new graph.
    let mut graph = Graph::new(5);

    // Add edges to the graph.
    graph.add_edge(0, 1, 1);
    graph.add_edge(0, 2, 4);
    graph.add_edge(1, 2, 2);
    graph.add_edge(1, 3, 5);
    graph.add_edge(2, 3, 1);
    graph.add_edge(3, 4, 3);

    let start_node = 0;

    // Find the shortest distances from the starting node.
    let shortest_distances = graph.shortest_path(start_node);

    // Print the results.
    for (node, distance) in shortest_distances.iter() {
        println!(
            "Shortest distance from node {} to node {}: {}",
            start_node, node, distance
        );
    }
}
