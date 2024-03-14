public class FactorialRecursive {

  public static void main(String[] args) {
    System.out.println("Fatorial de 0 : " + FactorialRecursive(0));
    System.out.println("Fatorial de 1 : " + FactorialRecursive(1));
    System.out.println("Fatorial de 3 : " + FactorialRecursive(3));
    System.out.println("Fatorial de 7 : " + FactorialRecursive(7));
  }

  public static int FactorialRecursive(int x) {
    if (x <= 1) return 1;
    else return x * FactorialRecursive(x - 1);
  }
}
