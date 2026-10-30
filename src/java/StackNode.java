public class StackNode {
  int key;
  StackNode prox;

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
    return prox;
  }

  public void setProx(StackNode prox) {
    this.prox = prox;
  }
}
