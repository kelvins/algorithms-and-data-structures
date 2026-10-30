/*
    Author: Gustavo Michels de Camargo
    GraphOperations: Structural graph algorithm
*/

use std::collections::HashMap;

// A vector of vectors used to represent the graph.
type GraphMatrix = Vec<Vec<isize>>;

// The dictionary lets us accept any String and map its position within
// the numeric matrix. This is for convenience, so callers do not need to convert a node label to a number.
#[derive(PartialEq, Eq, Clone, Debug)]
struct Graph {
    matrix: GraphMatrix,
    label_to_index: HashMap<String, usize>,
    bidirectional: bool,
}

trait GraphOperations {
    // General
    fn new(size: usize, direction: &str) -> Graph;

    // Dictionary-related functions - User-facing
    fn user_get_index(&self, key: String) -> usize;
    fn user_get_label(&self, index: usize) -> String;

    // User-facing operations
    fn user_add_edge(&mut self, a: String, b: String, value: isize);
    fn user_remove_edge(&mut self, a: String, b: String);
    fn user_edge_count(&self, node: String) -> usize;
    fn user_edge_exists(&self, a: String, b: String) -> bool;
    fn user_neighbors(&self, a: String) -> Vec<String>;

    // Machine / algorithm use
    fn add_edge(&mut self, a: usize, b: usize, value: isize);
    fn remove_edge(&mut self, a: usize, b: usize);
    fn edge_count(&self, node: usize) -> usize;
    fn edge_exists(&self, a: usize, b: usize) -> bool;
    fn neighbors(&self, a: usize) -> Vec<usize>;
}

// This is the implementation of a graph "class".
impl GraphOperations for Graph {
    // Size: maximum number of vertices the matrix can hold, from 0 to size.
    // In interval notation: [0, size).
    // Methods prefixed with 'user_' are intended for direct interaction with the user.
    // Methods without the 'user_' prefix should only be used internally by algorithms, such as Dijkstra for shortest paths between nodes.
    // This design improves performance and avoids repeatedly accessing and
    // querying the dictionary when an algorithm such as Dijkstra only needs to find a shortest path.

    // Only this function is an exception because it is universal.
    fn new(size: usize, direction: &str) -> Graph {
        Graph {
            matrix: vec![vec![-1; size]; size],
            label_to_index: HashMap::new(),
            bidirectional: match direction {
                "->" => false,     // Directed
                "<->" | _ => true, // Bidirectional
            },
        }
    }

    // ---- Functions for direct user interaction ----

    // Return the matrix index associated with the key
    fn user_get_index(&self, key: String) -> usize {
        if self.label_to_index.contains_key(&key) {
            return (&self.label_to_index.get(&key)).unwrap().clone();
        }

        return 0;
    }

    // Return the dictionary key associated with a graph matrix index
    fn user_get_label(&self, index: usize) -> String {
        for (key, value) in self.label_to_index.iter() {
            if *value == index {
                return (*key).clone();
            }
        }

        return "".to_string();
    }

    // Connect two vertices
    fn user_add_edge(&mut self, a: String, b: String, value: isize) {
        if !self.label_to_index.contains_key(&a) {
            let num: usize = self.label_to_index.len();
            self.label_to_index.insert(a.to_owned(), num);
        }

        if !self.label_to_index.contains_key(&b) {
            let num: usize = self.label_to_index.len();
            self.label_to_index.insert(b.to_owned(), num);
        }

        let (value_a, value_b): (usize, usize) = (self.user_get_index(a), self.user_get_index(b));

        self.matrix[value_a][value_b] = value;

        if self.bidirectional {
            self.matrix[value_b][value_a] = value;
        }
    }

    fn user_remove_edge(&mut self, a: String, b: String) {
        let (value_a, value_b): (usize, usize) = (self.user_get_index(a), self.user_get_index(b));

        self.matrix[value_a][value_b] = -1;
        self.matrix[value_b][value_a] = -1;
    }

    // Return the number of vertices connected to this one
    fn user_edge_count(&self, node: String) -> usize {
        self.matrix[self.user_get_index(node)]
            .iter()
            .filter(|x| **x >= 0)
            .collect::<Vec<&isize>>()
            .len() as usize
            | 0
    }

    // Check whether two nodes are connected
    fn user_edge_exists(&self, a: String, b: String) -> bool {
        self.matrix[self.user_get_index(a)][self.user_get_index(b)] >= 0
    }

    fn user_neighbors(&self, a: String) -> Vec<String> {
        let mut result: Vec<String> = Vec::new();
        let a_value: usize = self.user_get_index(a);

        for i in 0..self.matrix[a_value].len() {
            if a_value != i && self.matrix[a_value][i] > -1 {
                result.push(self.user_get_label(i));
            }
        }

        return result;
    }

    // ---- Functions for direct algorithm use (better performance) ----

    // Return an array of indices for all nodes connected to node 'a'
    // Use this function only internally within the graph, for algorithms such as Dijkstra.
    // Connect two vertices
    fn add_edge(&mut self, a: usize, b: usize, value: isize) {
        self.matrix[a][b] = value;

        if self.bidirectional {
            self.matrix[b][a] = value;
        }
    }

    fn remove_edge(&mut self, a: usize, b: usize) {
        self.matrix[a][b] = -1;
        self.matrix[b][a] = -1;
    }

    // Return the number of vertices connected to this one
    fn edge_count(&self, node: usize) -> usize {
        self.matrix[node]
            .iter()
            .filter(|x| **x >= 0)
            .collect::<Vec<&isize>>()
            .len() as usize
            | 0
    }

    fn edge_exists(&self, a: usize, b: usize) -> bool {
        self.matrix[a][b] >= 0
    }

    fn neighbors(&self, a: usize) -> Vec<usize> {
        let mut result: Vec<usize> = Vec::new();

        for i in 0..self.matrix[a].len() {
            if a != i && self.matrix[a][i] > -1 {
                result.push(i);
            }
        }
        return result;
    }
}

// Main
fn main() {
    // Graph with at most one thousand vertices
    // "->" = directed graph, "<->" = bidirectional graph
    let mut graph: Graph = Graph::new(1000, "->");

    graph.user_add_edge(0.to_string(), 1.to_string(), 1);
    graph.user_add_edge(1.to_string(), 2.to_string(), 1);
    graph.user_add_edge(2.to_string(), 3.to_string(), 1);
    graph.user_add_edge(3.to_string(), 0.to_string(), 1);

    println!("{:?}", graph.neighbors(2));
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn user_edge_count() {
        let mut graph: Graph = Graph::new(1000, "->");

        for i in 1..1000 {
            graph.user_add_edge(0.to_string(), i.to_string(), 1);
        }

        assert_eq!(graph.user_edge_count(0.to_string()), 999);
        assert_eq!(graph.user_edge_count(0.to_string()), graph.edge_count(0));
    }

    #[test]
    fn edge_count() {
        let mut graph: Graph = Graph::new(1000, "<->");

        for i in 1..1000 {
            graph.add_edge(0, i, 1);
        }

        assert_eq!(graph.edge_count(0), 999);
        assert_eq!(graph.edge_count(0), graph.user_edge_count(0.to_string()));
    }
}
