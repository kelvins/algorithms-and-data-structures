public class StackNode {
  int key;
  StackNode nextNode;

  public StackNode(int key) {
    this.key = key;
  }

  public int getKey() {
    return key;
  }

  public void setKey(int key) {
    this.key = key;
  }

  public StackNode getNextNode() {
    return nextNode;
  }

  public void setNextNode(StackNode nextNode) {
    this.nextNode = nextNode;
  }
}
