import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.List;

//Utilizado o OpenJDK 17.0.3
/*
 * @author Gabriel Nascimento. GitHub: Gabrielxdf
 *
 */
public class SomaDoisNumeros {
    /**
     * Para cada elemento da lista de valores, o método percorre o restante da lista
       verificando se há algum número cuja some de ambos seja o valor esperado.
     * @param valores Lista de valores que será verificada.
     * @param esperado Valor esperado pela soma de dois números da lista valores.
     */
    public static void verificaSeExisteSoma(List<Integer> valores, int esperado) {
        boolean resultado = false;
        for (int i = 0; i < valores.size() - 1; i++) {
            for (int j = i + 1; j < valores.size(); j++) {
                if (valores.get(i) + valores.get(j) == esperado) {
                    resultado = true;
                    System.out.println(MessageFormat.format("Verdadeiro - {0} + {1} = {2}", valores.get(i),
                            valores.get(j), esperado));
                    break;
                }
            }
            if (resultado) {
                break;
            }
        }
        if (!resultado) {
            System.out.println(MessageFormat.format("Falso - Não há dois números cuja soma seja {0}", esperado));
        }
    }

    public static void main(String[] args) {
        List<Integer> valores = new ArrayList<Integer>(List.of(12, 33, 5, 9, 54, 100));
        System.out.println("------Deve ser verdadeiro------");
        verificaSeExisteSoma(valores, 133);
        verificaSeExisteSoma(valores, 42);
        verificaSeExisteSoma(valores, 66);
        System.out.println("------Deve ser falso------");
        verificaSeExisteSoma(valores, 13);
        verificaSeExisteSoma(valores, 100);
        verificaSeExisteSoma(valores, 60);
    }
}
