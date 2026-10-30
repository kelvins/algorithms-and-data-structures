/*
    Autor: Gustavo Michels de Camargo
    Projeto: Algoritmo estrural de um Graph
*/

use std::collections::HashMap;

// Matrix de Vector usada ara construir o Graph.
type MatrizGrafo = Vec<Vec<isize>>;

// The dictionary lets us accept any String and map its position within
// the numeric matrix. This is for convenience, so callers do not need to convert a node label to a number.
#[derive(PartialEq, Eq, Clone, Debug)]
struct Graph {
    matrix: MatrizGrafo,
    dicionario: HashMap<String, usize>,
    bicondicional: bool,
}

trait Projeto {
    // Geral
    fn new(size: usize, tipo: &str) -> Graph;

    // Dictionary-related functions - User-facing
    fn usr_pegar_index(&self, key: String) -> usize;
    fn usr_pegar_chave(&self, index: usize) -> String;

    // Usuario
    fn usr_add_conexao(&mut self, a: String, b: String, value: isize);
    fn usr_remove_conexao(&mut self, a: String, b: String);
    fn usr_number_conexoes(&self, no: String) -> usize;
    fn usr_check_se_exists_conexao(&self, a: String, b: String) -> bool;
    fn usr_conexoes(&self, a: String) -> Vec<String>;

    // Machine / algorithm use
    fn add_conexao(&mut self, a: usize, b: usize, value: isize);
    fn remove_conexao(&mut self, a: usize, b: usize);
    fn number_conexoes(&self, no: usize) -> usize;
    fn check_se_exists_conexao(&self, a: usize, b: usize) -> bool;
    fn conexoes(&self, a: usize) -> Vec<usize>;
}

// This is the implementation of a graph "class".
impl Projeto for Graph {
    // Size: maximum number of vertices the matrix can hold, from 0 to size.
    // In interval notation: [0, size).
    // Functions prefixed with 'usr_' (usr = user) are intended for direct interaction with the user.
    // Functions with the same name but without 'usr_' should only be used internally by algorithms, such as Dijkstra for shortest paths between nodes.
    // This design improves performance and avoids repeatedly accessing and
    // querying the dictionary when an algorithm such as Dijkstra only needs to find a shortest path.

    // Only this function is an exception because it is universal.
    fn new(size: usize, tipo: &str) -> Graph {
        Graph {
            matrix: vec![vec![-1; size]; size],
            dicionario: HashMap::new(),
            bicondicional: match tipo {
                "->" => false,     // Condicional
                "<->" | _ => true, // Bicondicional
            },
        }
    }

    // ---- Functions for direct user interaction ----

    // Return the matrix index associated with the key
    fn usr_pegar_index(&self, key: String) -> usize {
        if self.dicionario.contains_key(&key) {
            return (&self.dicionario.get(&key)).unwrap().clone();
        }

        return 0;
    }

    // Return the dictionary key associated with a graph matrix index
    fn usr_pegar_chave(&self, index: usize) -> String {
        for (key, value) in self.dicionario.iter() {
            if *value == index {
                return (*key).clone();
            }
        }

        return "".to_string();
    }

    // Connect two vertices
    fn usr_add_conexao(&mut self, a: String, b: String, value: isize) {
        if !self.dicionario.contains_key(&a) {
            let num: usize = self.dicionario.len();
            self.dicionario.insert(a.to_owned(), num);
        }

        if !self.dicionario.contains_key(&b) {
            let num: usize = self.dicionario.len();
            self.dicionario.insert(b.to_owned(), num);
        }

        let (value_a, value_b): (usize, usize) =
            (self.usr_pegar_index(a), self.usr_pegar_index(b));

        self.matrix[value_a][value_b] = value;

        if self.bicondicional {
            self.matrix[value_b][value_a] = value;
        }
    }

    fn usr_remove_conexao(&mut self, a: String, b: String) {
        let (value_a, value_b): (usize, usize) =
            (self.usr_pegar_index(a), self.usr_pegar_index(b));

        self.matrix[value_a][value_b] = -1;
        self.matrix[value_b][value_a] = -1;
    }

    // Return the number of vertices connected to this one
    fn usr_number_conexoes(&self, no: String) -> usize {
        self.matrix[self.usr_pegar_index(no)]
            .iter()
            .filter(|x| **x >= 0)
            .collect::<Vec<&isize>>()
            .len() as usize
            | 0
    }

    // Check whether two nodes are connected
    fn usr_check_se_exists_conexao(&self, a: String, b: String) -> bool {
        self.matrix[self.usr_pegar_index(a)][self.usr_pegar_index(b)] >= 0
    }

    fn usr_conexoes(&self, a: String) -> Vec<String> {
        let mut result: Vec<String> = Vec::new();
        let a_value: usize = self.usr_pegar_index(a);

        for i in 0..self.matrix[a_value].len() {
            if a_value != i && self.matrix[a_value][i] > -1 {
                result.push(self.usr_pegar_chave(i));
            }
        }

        return result;
    }

    // ---- Functions for direct algorithm use (better performance) ----

    // Return an array of indices for all nodes connected to node 'a'
    // Use this function only internally within the graph, for algorithms such as Dijkstra.
    // Connect two vertices
    fn add_conexao(&mut self, a: usize, b: usize, value: isize) {
        self.matrix[a][b] = value;

        if self.bicondicional {
            self.matrix[b][a] = value;
        }
    }

    fn remove_conexao(&mut self, a: usize, b: usize) {
        self.matrix[a][b] = -1;
        self.matrix[b][a] = -1;
    }

    // Return the number of vertices connected to this one
    fn number_conexoes(&self, no: usize) -> usize {
        self.matrix[no]
            .iter()
            .filter(|x| **x >= 0)
            .collect::<Vec<&isize>>()
            .len() as usize
            | 0
    }

    fn check_se_exists_conexao(&self, a: usize, b: usize) -> bool {
        self.matrix[a][b] >= 0
    }

    fn conexoes(&self, a: usize) -> Vec<usize> {
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

    graph.usr_add_conexao(0.to_string(), 1.to_string(), 1);
    graph.usr_add_conexao(1.to_string(), 2.to_string(), 1);
    graph.usr_add_conexao(2.to_string(), 3.to_string(), 1);
    graph.usr_add_conexao(3.to_string(), 0.to_string(), 1);

    println!("{:?}", graph.conexoes(2));
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn usr_number_conexoes() {
        let mut graph: Graph = Graph::new(1000, "->");

        for i in 1..1000 {
            graph.usr_add_conexao(0.to_string(), i.to_string(), 1);
        }

        assert_eq!(graph.usr_number_conexoes(0.to_string()), 999);
        assert_eq!(
            graph.usr_number_conexoes(0.to_string()),
            graph.number_conexoes(0)
        );
    }

    #[test]
    fn number_conexoes() {
        let mut graph: Graph = Graph::new(1000, "<->");

        for i in 1..1000 {
            graph.add_conexao(0, i, 1);
        }

        assert_eq!(graph.number_conexoes(0), 999);
        assert_eq!(
            graph.number_conexoes(0),
            graph.usr_number_conexoes(0.to_string())
        );
    }
}
