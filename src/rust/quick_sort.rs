/*

    Contribuidores
        - Dromedario de chapeu

    O Quick Sort, é um dos algoritmos de ordenação padrões de se estudar.
    Ele é famoso por ser relativamente eficiente na maioria dos casos, tendo
    complexidade O(n log n). Porem em casos específicos ele pode chegar a ser
    O(n²) nos piores casos, como a lista estar basicamente invertida por exemplo.
    O Quick Sort adota a estrategia de "dividir e conquistar", que é resumidamente
    dividir a lista em sub 2 listas e organizar essas sub listas. A cada execução
    é escolhido o Pivot, e a partir deste Pivot nos comparamos todos os elementos
    da lista ate encontrar algum valor menor ou igual ao pivot, quando encontrarmos
    este valor, ele é colocado a frente do pivot. Quando passarmos por toda a
    lista, nos fazemos o swap entre o pivot e o ultimo índice que foi coloca a sua
    frene, assim nos teremos a garantia de que todos os itens a esquerda do pivot
    sejam menores, e os a direita maiores. E assim nos pegamos essas 2 novas listas,
    e fazemos o mesmo processo.

    Recomendo dar uma olhada mais profunda sobre o funcionado e casos específicos,
    como os diferentes métodos de partição e funcionado com múltiplos pivot's, prometo
    que é algo mais interessante e menos chato do que parece.
        Links: https://pt.wikipedia.org/wiki/Quicksort
               https://rosettacode.org/wiki/Sorting_algorithms/Quicksort

*/

// l = limite esquerdo
// r = limite direito
// These bounds are passed instead of creating a new list at each split
// so we always work on the same list and update its values
// and because creating new lists during recursion would be expensive.
fn partition(lista: &mut [i32], l: usize, r: usize) -> isize {
    // Set the first item in the list as the pivot
    let pivot = lista[l];

    // To move values less than or equal to the pivot before it,
    // we need a variable to count how many positions to move forward
    // the next value without repeatedly swapping the same value.
    let mut count = l;

    // Use a for loop to iterate over the list. We do not use enumerate because we need
    // simulate the sublists
    for j in l + 1..r + 1 {
        if lista[j] <= pivot {
            count += 1;
            lista.swap(count, j);
        }
    }

    // Swap the pivot with the last value that is less than or equal to it, because
    lista.swap(l, count);

    // Return the pivot’s index after the swap so it can be used
    // as the boundary for the two sublists: 0..count - 1 and count + 1..len.
    // the new sublists.
    return count as isize;
}

fn quick_sort(lista: &mut [i32], l: isize, r: isize) {
    // The recursion stops when the left and right bounds
    // are equal, meaning the list has only one element.
    if l < r {
        let indice_pivot = partition(lista, l as usize, r as usize);
        quick_sort(lista, l, indice_pivot - 1);
        quick_sort(lista, indice_pivot + 1, r);
    }
}

fn printa(lista: Vec<i32>) {
    for i in lista.iter() {
        print!("{} ", *i);
    }
    println!();
}

fn main() {
    let mut lista = vec![1, 6, 3, 9, 3, 8, 5, 2, 7];
    let len = lista.len() as isize;

    printa(lista.clone());
    quick_sort(&mut lista, 0, len - 1);
    printa(lista.clone());
}

#[cfg(test)]
mod test {
    use crate::*;

    #[test]
    fn quick() {
        let mut lista = vec![9, 8, 7, 6, 5, 4, 3, 2, 1];
        let len = lista.len() as isize - 1;
        quick_sort(&mut lista, 0, len);
        assert_eq!(vec![1, 2, 3, 4, 5, 6, 7, 8, 9], lista);

        let mut lista = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
        let len = lista.len() as isize - 1;
        quick_sort(&mut lista, 0, len);
        assert_eq!(vec![1, 2, 3, 4, 5, 6, 7, 8, 9], lista);
    }
}
