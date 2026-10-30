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

  public StackNode getProx() {
    return nextNode;
  }

  public void setProx(StackNode nextNode) {
    this.nextNode = nextNode;
  }
}
