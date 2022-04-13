/*
    Contribuidores
        - Dromedário de Chapéu

    A Busca Sequencial Recursiva consiste do mesmo conceito da Busca Sequencial.
    A diferença é que ao invés de iterar na lista utilizando um for por exemplo,
    é utilizado recursão que é resumidamente uma função que se chama N vezes com
    mudanças no seus parâmetros te atingir ou o resultado desejado, ou um estado
    onde não ha mais o que fazer.

    Essa implementação é ainda mais lenta e custosa que a forma utilizando for,
    pois recursão utiliza muito mais memoria e processamento para ser utilizada, para
    poucos itens na pratica ele vai ser tão rápido quanto qualquer outro algoritmo.
    Porem caso seja uma lista de milhares de itens este algoritmo sera um problema.
*/

// A mudança da declaração da sequencial normal para esta é a adição do parâmetro
// índice, que indica em qual índice da lista nos estamos.
fn busca_sequencial_recursiva(lista: &[i32], valor: i32, indice: usize) -> (bool, usize) {
    // O primeiro If indica a condição onde a recursão ocorreu vezes o suficiente
    // para que o índice chega ao final da lista + 1, logo todos os itens da lista
    // foram percorridos
    if indice == lista.len() {
        return (false, 0)
    } else if lista[indice] == valor {
        return (true, indice)
    }

    // Caso o item atual não seja o item desejado, nos chamamos a função com o índice
    // acrescentado, para que na próxima execução da função seja verificado o próximo
    // item da lista
    return busca_sequencial_recursiva(lista, valor, indice + 1);
}

fn main() {
    let lista = vec![1, 2, 3, 4];
    let (existe, indice) = busca_sequencial_recursiva(&lista, 0, 0);
    println!("{}, {}", existe, indice);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn busca() {
        let lista = vec![1, 2, 3, 4];
        assert_eq!(busca_sequencial_recursiva(&lista, 2, 0), (true, 1));
        assert_eq!(busca_sequencial_recursiva(&lista, 0, 0), (false, 0));
    }
}
