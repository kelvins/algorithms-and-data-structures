public class No {
  int key;
  No left, right;

  public No(int key) {
    this.key = key;
    this.left = null;
    this.right = null;
  }

  public int getChave() {
    return key;
  }

  public void setChave(int key) {
    this.key = key;
  }

  public No getEsq() {
    return left;
  }

  public void setEsq(No left) {
    this.left = left;
  }

  public No getDir() {
    return right;
  }

  public void setDir(No right) {
    this.right = right;
  }

  @Override
  public String toString() {
    return "No{" + "key: " + key + ", left: " + left + ", right: " + right + '}';
  }
}
