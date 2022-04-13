/*
    Contribuidores
        - Dromedario de Chapéu

    O Bogo Sort é um algoritmo feito apenas como uma piada, sendo
    o pior e mais demorado algoritmo de ordenação. Tudo o que ele faz
    é pegar uma lista, randomizar os seus itens, e verificar se todos
    os itens estão ordenados. Logo, ele é 100% aleatório, o que pode
    fazer com que demore mais de 1 milhão de tentativas até ser ordenado,
    ou que simplesmente na primeira tentativa ele seja ordenado.

*/

// Para utilizar esta lib sera necessário iniciar um projeto com o cargo
// e adicionar Rand as dependências
use rand::prelude::*;

fn verifica_ordem(lista: Vec<u8>) -> bool {
    for indice in 0..lista.len() - 1 {
        if lista[indice] > lista[indice + 1] {
            return false;
        }
    }
    return true;
}

// Vec<u8> significa que o parâmetro "lista" é uma lista de
// inteiros sem sinal de 8 bits. E o retorno u64 se refere
// ao total de ciclos necessários para realizar a ordenação
fn bogo_sort(mut lista: Vec<u8>) -> (Vec<u8>, u64) {
    let mut rng = thread_rng();
    // Foi escolhido um limite tão grande justamente pelo bogo sort
    // poder ser tanto o algoritmo mais rápido quanto o mais lento,
    // então para não crashar o programa é bom um range grande
    let mut ciclos: u64 = 0;
    loop {
        ciclos +=1;
        lista.shuffle(&mut rng);
        if verifica_ordem(lista.clone()) {
            return (lista, ciclos);
        }
    }
}

// O valor de u8 para os itens da lista é apenas para
// gerar números muito grandes e dificultar na visualização
fn gera_lista(len: u8) -> Vec<u8> {
    let mut rng = thread_rng();
    let mut lista = Vec::<u8>::new();
    for _ in 0..len - 1 {
        lista.push(rng.gen());
    }
    return lista;
}

fn main() {
    let lista_desordenada = gera_lista(6);
    print!("Lista desordenada: ");
    for i in lista_desordenada.iter() {
        print!("{i} ")
    }
    println!();

    let (lista, ciclos) = bogo_sort(lista_desordenada);
    println!("Foram necesarios um total de {ciclos} para ordenar");
    print!("Lista ordenada: ");
    for i in lista.iter() {
        print!("{i} ");
    }
    println!();
}

// Testes unitarios
#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn oredenacao() {
        let mut desordenada = gera_lista(6);
        let (ordenada, _) = bogo_sort(desordenada.clone());
        desordenada.sort();
        assert_eq!(ordenada, desordenada);

        let desordenada = vec![6, 5, 4, 3, 2, 1];
        let (ordenada, _) = bogo_sort(desordenada);
        assert_eq!(ordenada, vec![1, 2, 3, 4, 5, 6]);
    }
}
