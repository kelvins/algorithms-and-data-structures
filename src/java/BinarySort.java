package algoritmosOrdenacao;

/**
 * Contribuidores:
 *  vinicius-developer
 *
 *  Descrição:
 *
 *  Busca binária é um dos algoritmos de busca em lista clássico da ciẽncia de computação
 *  e apesar de parecer complicado, é simples.
 *
 *  (Muitas vezes o que complica é a explicação do professor rsrs)
 *
 *  A ideia da busca binária é a seguinte:
 *
 *  1. Primeiro você precisa de uma lista organizada do menor para o maior, então só é possível
 *  aplicar uma busca binária em uma lista de itens que são comparáveis entre sí.
 *
 *  2. Para exemplo vamos usar uma lista de 1 até 10 como no exemplo a baixo:
 *
 *  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 *
 *  3. Vamos dizer que que gostariamos de procurar o número 9, então:
 *
 *  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 *
 *  numero: 9
 *
 *  4. Para procurar ao invés de passar em cada item do array, vamos tentar uma abordagem
 *  diferente, que tal tentarmos compara com a métade do array?
 *
 *  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 *               ^
 *               9
 *  5. Vamos fazer um pergunta aqui 8 é igual a 5? Não, então 9 é menor que 5? Também não.
 *  Ótimo com essas informações, e como nossa lista está organizada do menor para o maior
 *  não precisamos procurar na parte da esquerda dela porque sabemos que lá só existem números
 *  menores que 5. Então agora vamos eleminar os números que não são iguais a 9 da nossa lista:
 *
 *  [6, 7, 8, 9, 10]
 *
 *  numero: 9
 *
 *  6. Agora certo vemos repetir o processo qual é o número do meio? Nesse caso é 8 então:
 *
 *  [6, 7, 8, 9, 10]
 *         ^
 *         9
 *  7. Mais uma vez não é igual vamos repetir o processo de eleminação
 *
 *  [9, 10]
 *
 *  numero: 9
 *
 *  8. Agora só temos dois números e nenhum que seria considerado o meio, o que acontece?
 *  Podemos comparar com o menor ou com o maior de qualquer forma ele irá executar uma busca
 *  a mais nesse caso se compararmos com o menor é o número que estamos procurando.
 *
 *  Observaçãoes: Nesse caso nós escolhemos um número grande e formos descatandado os números
 *  menores, mas também é normal que na comparação dercartamos o números menores até chegar no
 *  numero desajado.
 *
 */
public class BinarySort {

    public static void main(String[] args) {

        int[] list = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

        System.out.println(binarySearch(-1, list, 0, (list.length - 1)));

    }


    private static boolean binarySearch(int searchValue, int[] list, int leftValue, int rightValue) {

        int middle = (leftValue + rightValue) / 2;

        if(leftValue <= rightValue) {

            if(searchValue > list[middle]) {

                leftValue = middle + 1;

                return BuscaBinaria.binarySearch(searchValue, list, leftValue, rightValue);

            } else if(searchValue < list[middle]) {

                rightValue = middle - 1;

                return BuscaBinaria.binarySearch(searchValue, list, leftValue, rightValue);

            } else {

                return true;

            }

        }

        return false;

    }


}
