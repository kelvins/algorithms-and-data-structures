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

// O <T> em Rust indica que não se espera tipo especifico e sim qualquer tipo
// no caso o T é usado para indicar o tipo dos valores da lista e o valor a ser
// procurado.
fn busca_binaria<T>(lista: &[T], valor: T) -> (bool, usize)
where
    // É preciso especificar que T implementa as Traits PartialEq e PartialOrd para
    // indicar que T pode ser comparado T e que possui uma ordem de maior e menor
    T: PartialEq,
    T: PartialOrd,
{
    // Centro indica o centro a lista ou sublista
    let mut centro = lista.len() / 2;

    // Limite_r representa o maior indice possível, referente ao extremo direito
    // da lista atual, serve para dividir a lista original sem precisar ficar
    // clonando ou literalmente dividindo. Seria o [-1] da sublista
    let mut limite_r = lista.len() - 1;

    // Limite_l representa o mesmo que Limite_r porem para o extremo esquerdo,
    // ou seja, o [0] da sub lista.
    let mut limite_l = 0;

    loop {
        // O valor esta sendo passado por referencia e depois acessado pelo seu
        // ponteiro pelo sistema de ownership o Rust, isso pode feito com atribuição
        // simples como `valor_p = lista[centro]` em um Python por exemplo
        let valor_p = &lista[centro];

        // O primeiro bloco de if se responsabiliza em verificar se o valor que estamos
        // buscado foi encontrado, caso não ele verifica da ultima operação para esta
        // o centro não mudou de posição, ou seja, não ha mais valores para verificar
        // e o item não existe
        if *valor_p == valor {
            return (true, centro)
        } else if centro == limite_l && centro == limite_r {
            return (false, 0)
        }

        // O segundo bloco se responsabiliza em verificar a distancia entre o valor recebido
        // e o atual valor_p, caso seja valor_p seja maior, significa que o valor procurado
        // esta mais para trás, e o centro é movido para o centro da sub lista anterior.
        // Porem caso valor seja maior que o valor_p, significa que precisamos mover o centro
        // para o centro da sub lista superiors
        if *valor_p > valor {
            limite_r = centro;
            centro = centro / 2;
        } else if *valor_p < valor {
            limite_l = centro;
            // O If esta verificando se o espaço entre limite_r e limite_l é igual a 1
            // pois a operação de padrão usada daria o resultado de 0 nesse caso, pois
            // Rust arredonda os valores para baixo, logo 0.5 é jogado para 0
            // Poderia ser feito em uma linha utilizado conversão de tipos e arredondamento
            // porem eu pessoalmente acredito que a performance ganha não vale compensa

            centro = if (limite_r - limite_l) == 1 { centro + 1 }
                     else { centro + (limite_r - limite_l) / 2 };
            // Forma em uma linha -
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
