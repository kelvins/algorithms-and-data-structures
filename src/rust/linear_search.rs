/*
    Contribuidores
        - Dromedario de Chapéu

    Search Sequencial é o mais simples algoritmo de search possessive, alem de
    ser um dos menos eficientes. Ele simplesmente itera por todos os itens
    de uma list até find o value desejado ou atingir o final da list
    retornando que o element não esta presente na list.

    Esse algoritmo pode ser útil para lists pequenas de algumas poucas centenas
    de values de tipo simples, porem mais que isso ele sera um grande gargalo
    durante a execução do programa.

    Uma possível vantagem deste algoritmo, é que ele independe da list estar
    ordenada para funcionar, pois ele não se importa com a order dos elements.
*/
fn busca_sequencial(list: &[i32], value: i32) -> (bool, usize) {
    for (i, c) in list.iter().enumerate() {
        if *c == value {
            return (true, i);
        }
    }
    return (false, 0);
}

fn main() {
    let list = vec![1, 2, 3, 4];
    let (existe, index) = busca_sequencial(&list, 2);
    println!("{}, {}", existe, index);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn search() {
        let list = vec![1, 2, 3, 4];
        assert_eq!(busca_sequencial(&list, 2), (true, 1));
        assert_eq!(busca_sequencial(&list, 0), (false, 0));
    }
}
