public class CalculatePi {
    public static void main(String[] args) {
        int[] terms = {10, 1000, 100000, 10000000};

        for (int i = 0; i < terms.length; i++) {
            System.out.println("(" + terms[i] + "): " + leibniz_pi_calculation(terms[i]));
        }
    }

    public static double leibniz_pi_calculation(int number) {
        double denominador = 1.0;
        double operacao = 1.0;
        double pi = 0.0;

        for (int i = 0; i < number; i++) {
            pi += operacao * (4.0 / denominador);
            denominador += 2.0;
            operacao *= -1.0;
        }
        return pi;
    }

}
