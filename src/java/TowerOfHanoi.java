public class TowerOfHanoi {

  public static void main(String[] args) {
    towerOfHanoi(0, 2, 1, 8);
  }

  public static void towerOfHanoi(int source, int destination, int auxiliary, int diskCount) {
    if (diskCount == 1) {
      System.out.println("Move from " + source + " to " + destination);
    } else {
      towerOfHanoi(source, auxiliary, destination, diskCount - 1);
      towerOfHanoi(source, destination, auxiliary, 1);
      towerOfHanoi(auxiliary, destination, source, diskCount - 1);
    }
  }
}
