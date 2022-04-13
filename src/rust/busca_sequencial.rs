/*
    Contribuidores
        - Dromedario de Chapéu

    Busca Sequencial é o mais simples algoritmo de busca possessive, alem de
    ser um dos menos eficientes. Ele simplesmente itera por todos os itens
    de uma lista até encontrar o valor desejado ou atingir o final da lista
    retornando que o elemento não esta presente na lista.

    Esse algoritmo pode ser útil para listas pequenas de algumas poucas centenas
    de valores de tipo simples, porem mais que isso ele sera um grande gargalo
    durante a execução do programa.

    Uma possível vantagem deste algoritmo, é que ele independe da lista estar
    ordenada para funcionar, pois ele não se importa com a ordem dos elementos.
*/
fn busca_sequencial(lista: &[i32], valor: i32) -> (bool, usize) {
    for (i, c) in lista.iter().enumerate() {
        if *c == valor {
            return (true, i);
        }
    }
    return (false, 0);
}

fn main() {
    let lista = vec![1, 2, 3, 4];
    let (existe, indice) = busca_sequencial(&lista, 2);
    println!("{}, {}", existe, indice);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn busca() {
        let lista = vec![1, 2, 3, 4];
        assert_eq!(busca_sequencial(&lista, 2), (true, 1));
        assert_eq!(busca_sequencial(&lista, 0), (false, 0));
    }
}
