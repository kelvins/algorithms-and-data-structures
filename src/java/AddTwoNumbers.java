import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.List;

// Utilized OpenJDK 17.0.3
/*
 * @author Gabriel Nascimento. GitHub: Gabrielxdf
 *
 */
public class AddTwoNumbers {
  /**
   * This program takes a list of numbers and checks if there are two numbers whose sum is equal to
   * the expected value.
   *
   * <p>For each element in the list of values, this method goes through the list, checking if there
   * is any number whose sum of both is the expected value.
   *
   * @param values List of values that will be checked.
   * @param expected Expected value from the sum of two numbers from the values list.
   */
  public static void checkIfThereSumExists(List<Integer> values, int expected) {
    boolean result = false;
    for (int i = 0; i < values.size() - 1; i++) {
      for (int j = i + 1; j < values.size(); j++) {
        if (values.get(i) + values.get(j) == expected) {
          result = true;
          System.out.println(
              MessageFormat.format(
                  "True - {0} + {1} = {2}", values.get(i), values.get(j), expected));
          break;
        }
      }
      if (result) {
        break;
      }
    }
    if (!result) {
      System.out.println(
          MessageFormat.format("False - There are no two numbers whose sum is {0}", expected));
    }
  }

  public static void main(String[] args) {
    List<Integer> values = new ArrayList<Integer>(List.of(12, 33, 5, 9, 54, 100));
    System.out.println("------It must be true------");
    checkIfThereSumExists(values, 133);
    checkIfThereSumExists(values, 42);
    checkIfThereSumExists(values, 66);
    System.out.println("------It must be false------");
    checkIfThereSumExists(values, 13);
    checkIfThereSumExists(values, 100);
    checkIfThereSumExists(values, 60);
  }
}
