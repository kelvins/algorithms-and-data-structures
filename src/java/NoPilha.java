public class NoPilha {
  int key;
  NoPilha prox;

  public NoPilha(int key) {
    this.key = key;
  }

  public int getChave() {
    return key;
  }

  public void setChave(int key) {
    this.key = key;
  }

  public NoPilha getProx() {
    return prox;
  }

  public void setProx(NoPilha prox) {
    this.prox = prox;
  }
}
