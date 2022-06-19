/*
	Autor: Gustavo Michels de Camargo
	Projeto: Algoritmo estrural de um Grafo
*/


use std::{collections::HashMap};

// Matriz de Vector usada ara construir o Grafo.
type MatrizGrafo = Vec<Vec<isize>>;



// O dicionario serve para podermos dar entrada a qualquer String e ter como abstrair suas posições dentro
// da matriz numerica, isso serve apenas para fins de uso, não requerer transcrever um Nodo com X para valor numerico.
#[derive(PartialEq, Eq, Clone, Debug)]
struct Grafo {
	matriz: MatrizGrafo,
	dicionario: HashMap<String, usize>,
	bicondicional: bool
}

trait Projeto {
	// Geral
	fn new(tamanho: usize, tipo: &str) -> Grafo;

	// Funções envolvendo o dicionario - Usuario
	fn usr_pegar_indice(&self, chave: String) -> usize;
	fn usr_pegar_chave(&self, indice: usize) -> String;

	// Usuario
	fn usr_adicionar_conexao(&mut self, a: String, b: String, valor: isize);
	fn usr_remover_conexao(&mut self, a: String, b: String);
	fn usr_numero_conexoes(&self, no: String) -> usize;
	fn usr_verificar_se_existe_conexao(&self, a: String, b: String) -> bool;
	fn usr_conexoes(&self, a: String) -> Vec<String>;

	// Maquina / uso para os Algoritmos
	fn adicionar_conexao(&mut self, a: usize, b: usize, valor: isize);
	fn remover_conexao(&mut self, a: usize, b: usize);
	fn numero_conexoes(&self, no: usize) -> usize;
	fn verificar_se_existe_conexao(&self, a: usize, b: usize) -> bool;
	fn conexoes(&self, a: usize) -> Vec<usize>;
}


// Este é a implementação da "Classe" de um grafo.
impl Projeto for Grafo {
	// Tamanho: Numero Maximo de Vertices que a matriz pode usar de 0 até tamanho.
	// Em notação matematica relativa a limites: [0, tamanho).
	// Toda função que começa com 'usr_'(usr = usuario) é a versão da função que deve ser usada para interagir diretamente com o usuario.
	// As funções de mesmo nome mas sem 'usr_' deve ser usada apenas dentro dos algoritmos, como o Dijkstra para menor caminho entre dois nos.
	// Fiz assim para otimizar processamento e descartar necessidade de acessar e 
	// consultar o dicionario o tempo todo quando se apenas tem como Objetivo encontrar um menor caminho com Dijkstra por exemplo.
	
	// Apenas essa função foge a regra por ser universal
	fn new(tamanho: usize, tipo: &str) -> Grafo {
		Grafo {
			matriz: vec![vec![-1; tamanho]; tamanho],
			dicionario: HashMap::new(),
			bicondicional: match tipo  {
				"->" => false, // Condicional
				"<->" | _ => true // Bicondicional
			}
		}
	}

	// ---- Funções para uso direto do usuario ----

	// Retorna o indice da matriz relacionada a chave
	fn usr_pegar_indice(&self, chave: String) -> usize {
		if self.dicionario.contains_key(&chave) {
			return (&self.dicionario.get(&chave)).unwrap().clone();
		}
		
		return 0;
	}

	// Retorna a chave do dicionario relacionada ao valor do indice da matriz do grafo
	fn usr_pegar_chave(&self, indice: usize) -> String {
		for (key, value) in self.dicionario.iter() {
			if *value == indice {
				return (*key).clone();
			}
		}

		return "".to_string();
	}
	
	// Conecta Dois vertices
	fn usr_adicionar_conexao(&mut self, a: String, b: String, valor: isize) {
		if !self.dicionario.contains_key(&a){
			let num: usize = self.dicionario.len();
			self.dicionario.insert(a.to_owned(), num);
		}

		if !self.dicionario.contains_key(&b){
			let num: usize = self.dicionario.len();
			self.dicionario.insert(b.to_owned(), num);
		}

		let (valor_a, valor_b): (usize, usize) = (self.usr_pegar_indice(a), self.usr_pegar_indice(b));

		self.matriz[valor_a][valor_b] = valor;

		if self.bicondicional {
			self.matriz[valor_b][valor_a] = valor;
		}
		
	}

	fn usr_remover_conexao(&mut self, a: String, b: String) {
		let (valor_a, valor_b): (usize, usize) = (self.usr_pegar_indice(a), self.usr_pegar_indice(b));

		self.matriz[valor_a][valor_b]  = -1;
		self.matriz[valor_b][valor_a]  = -1;
	}

	// Retorba o numero de vertices na qual ele se conecta
	fn usr_numero_conexoes(&self, no: String) -> usize {
		self.matriz[self.usr_pegar_indice(no)].iter()
						.filter(|x| **x >= 0)
						.collect::<Vec<&isize>>()
						.len() as usize | 0
	}

	// Verifica se dois nos estão conectados
	fn usr_verificar_se_existe_conexao(&self, a: String, b: String) -> bool {
		self.matriz[self.usr_pegar_indice(a)][self.usr_pegar_indice(b)]  >= 0
	}


	fn usr_conexoes(&self, a: String) -> Vec<String> {
		let mut result: Vec<String> = Vec::new();
		let a_value: usize = self.usr_pegar_indice(a);

		for i in 0..self.matriz[a_value].len() {
			if a_value != i && self.matriz[a_value][i] > -1 {
				result.push(self.usr_pegar_chave(i));
			}
		}

		return result;
	}



	// ---- Funções para uso direto dos algoritmos (tem melhor perfomance) ----


	// Retorna um array dos indice de todos os nos na qual o no 'a' se conecta
	// Espera se usar esta função apenas para usos proprios dentro do Grafo, como em algoritmos tipo dijkstra
	// Conecta Dois vertices
	fn adicionar_conexao(&mut self, a: usize, b: usize, valor: isize) {
		self.matriz[a][b] = valor;

		if self.bicondicional {
			self.matriz[b][a] = valor;
		}
	}

	fn remover_conexao(&mut self, a: usize, b: usize) {
		self.matriz[a][b]  = -1;
		self.matriz[b][a]  = -1;
	}

	// Retorba o numero de vertices na qual ele se conecta
	fn numero_conexoes(&self, no: usize) -> usize {
		self.matriz[no].iter()
						.filter(|x| **x >= 0)
						.collect::<Vec<&isize>>()
						.len() as usize | 0
	}

	fn verificar_se_existe_conexao(&self, a: usize, b: usize) -> bool {
		self.matriz[a][b]  >= 0
	}

	fn conexoes(&self, a: usize) -> Vec<usize> {
		let mut result: Vec<usize> = Vec::new();

		for i in 0..self.matriz[a].len() {
			if a != i && self.matriz[a][i] > -1 {
				result.push(i);
			}
		}
		return result;
	}

}


// Main
fn main() {
	// Grafo com no maximo mil vertices
	 // "->" =  Grafo condicional, "<->" = Grafo Bicondicional
	let mut grafo: Grafo = Grafo::new(1000, "->");
	
	grafo.usr_adicionar_conexao(0.to_string(), 1.to_string(), 1);
	grafo.usr_adicionar_conexao(1.to_string(), 2.to_string(), 1);
	grafo.usr_adicionar_conexao(2.to_string(), 3.to_string(), 1);
	grafo.usr_adicionar_conexao(3.to_string(), 0.to_string(), 1);

	println!("{:?}", grafo.conexoes(2));
}


#[cfg(test)]
mod test {
	use super::*;

	#[test]
	fn usr_numero_conexoes() {
		let mut grafo: Grafo = Grafo::new(1000, "->");

		for i in 1..1000 {
			grafo.usr_adicionar_conexao(0.to_string(), i.to_string(), 1);
		}

		assert_eq!(grafo.usr_numero_conexoes(0.to_string()), 999);
		assert_eq!(grafo.usr_numero_conexoes(0.to_string()), grafo.numero_conexoes(0));
	}

	#[test]
	fn numero_conexoes() {
		let mut grafo: Grafo = Grafo::new(1000, "<->");

		for i in 1..1000 {
			grafo.adicionar_conexao(0, i, 1);
		}

		assert_eq!(grafo.numero_conexoes(0), 999);
		assert_eq!(grafo.numero_conexoes(0), grafo.usr_numero_conexoes(0.to_string()));
	}
} 
