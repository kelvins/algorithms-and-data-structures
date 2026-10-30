/*
    Contribuidores
        - Dromedario de Chapéu

        O que é busca Binaria -
    "A busca binária é um eficiente algoritmo para encontrar um item em uma lista
    ordenada de itens. Ela funciona dividindo repetidamente pela metade a porção da
    lista que deve conter o item, até reduzir as localizações possíveis a apenas uma.
    Nós usamos a busca binária em um jogo de adivinhação no tutorial introdutório."
        - Khan Academy : https://pt.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search
*/

// In Rust, <T> indicates a generic type rather than a specific type.
// Here, T is the type of the list values and the value to be
// searched for.
fn busca_binaria<T>(lista: &[T], valor: T) -> (bool, usize)
where
    // T must implement the PartialEq and PartialOrd traits so
    // it can be compared and ordered.
    T: PartialEq,
    T: PartialOrd,
{
    // center is the midpoint of the list or sublist.
    let mut centro = lista.len() / 2;

    // limit_r is the greatest possible index, at the right edge
    // of the current list. It lets us narrow the original list without
    // cloning or physically splitting it. It acts as the sublist’s [-1].
    let mut limite_r = lista.len() - 1;

    // limit_l is like limit_r, but for the left edge,
    // that is, the sublist’s [0].
    let mut limite_l = 0;

    loop {
        // The value is passed by reference and accessed through its
        // pointer under Rust’s ownership system. This can be done with a simple
        // assignment such as `valor_p = lista[centro]` in Python, for example.
        let valor_p = &lista[centro];

        // The first if block checks whether the value we are
        // searching for was found. If not, it checks whether the previous operation left
        // the midpoint unchanged, meaning there are no more values to check
        // and the item is not present.
        if *valor_p == valor {
            return (true, centro);
        } else if centro == limite_l && centro == limite_r {
            return (false, 0);
        }

        // The second block checks the distance between the input value
        // and the current value_p. If value_p is greater, the target
        // is earlier in the list, so center moves to the midpoint of the previous sublist.
        // If value is greater than value_p, move center
        // to the midpoint of the next sublist.
        if *valor_p > valor {
            limite_r = centro;
            centro = centro / 2;
        } else if *valor_p < valor {
            limite_l = centro;
            // This if checks whether the gap between limit_r and limit_l is 1
            // because the default operation would produce 0 in that case, since
            // Rust rounds down, so 0.5 becomes 0.
            // This could be done on one line using type conversion and rounding,
            // but I do not think the performance gain is worth it.

            centro = if (limite_r - limite_l) == 1 {
                centro + 1
            } else {
                centro + (limite_r - limite_l) / 2
            };
            // One-line version -
            //     centro = centro + (((limite_r - limite_l) as f32 / 2.0).ceil() as usize);
        }
    }
}

fn main() {
    let lista = vec![-5, -4, -3, -2, -1];
    let (existe, centro) = busca_binaria(&lista, 6);
    println!("{}, {}", existe, centro);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn busca() {
        let lista = vec![-3, -2, -1, 0, 1, 2, 3];
        assert_eq!(busca_binaria(&lista, -7), (false, 0));
        assert_eq!(busca_binaria(&lista, -2), (true, 1));
        assert_eq!(busca_binaria(&lista, 0), (true, 3));
        assert_eq!(busca_binaria(&lista, 2), (true, 5));
        assert_eq!(busca_binaria(&lista, 7), (false, 0));
    }
}
