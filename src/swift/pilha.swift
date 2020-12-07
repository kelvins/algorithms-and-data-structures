//
//  pilha.swift
//  
//
//  Created by Matheus Torres on 14/11/20.
//

class Pilha {
    var pilha: [Int] = []
    
    func empilhar(_ value: Int) {
        pilha.append(value)
    }
    
    func desempilhar() {
        pilha.removeLast()
    }
    
    func ler() {
        print(pilha)
    }
    
    func esvaziar() {
        pilha = []
    }
}

let pilha = Pilha()

pilha.empilhar(1)
pilha.empilhar(2)
pilha.empilhar(3)
pilha.empilhar(4)

pilha.ler()

pilha.desempilhar()
pilha.desempilhar()
pilha.ler()

