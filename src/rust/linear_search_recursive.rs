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

// The only change from the regular linear search declaration is the added parameter
// index, which indicates the current position in the list.
fn busca_sequencial_recursiva(lista: &[i32], valor: i32, indice: usize) -> (bool, usize) {
    // The first if checks whether recursion has advanced far enough
    // for the index to reach the end of the list; all items have then
    // been checked.
    if indice == lista.len() {
        return (false, 0);
    } else if lista[indice] == valor {
        return (true, indice);
    }

    // If the current item is not the target, call the function again with the index
    // incremented so the next call checks the next
    // item in the list.
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
