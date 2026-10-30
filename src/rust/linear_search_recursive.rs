/*
    Contribuidores
        - Dromedário de Chapéu

    A Search Sequencial Recursiva consiste do mesmo conceito da Search Sequencial.
    A diferença é que ao invés de iterar na list utilizando um for por exemplo,
    é utilizado recursão que é resumidamente uma função que se chama N vezes com
    mudanças no seus parâmetros te atingir ou o result desejado, ou um estado
    onde not ha mais o que fazer.

    Essa implementação é ainda mais lenta e custosa que a forma utilizando for,
    pois recursão utiliza muito mais memoria e processamento para ser utilizada, para
    poucos itens na pratica ele vai ser tão rápido quanto qualquer outro algoritmo.
    Porem caso seja uma list de milhares de itens este algoritmo sera um problema.
*/

// The only change from the regular linear search declaration is the added parameter
// index, which indicates the current position in the list.
fn search_sequential_recursive(list: &[i32], value: i32, index: usize) -> (bool, usize) {
    // The first if checks whether recursion has advanced far enough
    // for the index to reach the end of the list; all items have then
    // been checked.
    if index == list.len() {
        return (false, 0);
    } else if list[index] == value {
        return (true, index);
    }

    // If the current item is not the target, call the function again with the index
    // incremented so the next call checks the next
    // item in the list.
    return search_sequential_recursive(list, value, index + 1);
}

fn main() {
    let list = vec![1, 2, 3, 4];
    let (exists, index) = search_sequential_recursive(&list, 0, 0);
    println!("{}, {}", exists, index);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn search() {
        let list = vec![1, 2, 3, 4];
        assert_eq!(search_sequential_recursive(&list, 2, 0), (true, 1));
        assert_eq!(search_sequential_recursive(&list, 0, 0), (false, 0));
    }
}
