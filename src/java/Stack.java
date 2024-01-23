public class Stack<T> {

  public T processoAtual;
  public Stack<T> proximaPilha;

  public Stack() {
    this.processoAtual = null;
    this.proximaPilha = null;
  }

  public void inserirpilha(T processoNovo) {
    if (this.processoAtual == null) {
      this.processoAtual = processoNovo;
      this.proximaPilha = new Stack<>();
    } else {
      this.proximaPilha.inserirpilha(processoNovo);
    }
  }

  public T removerPilha() {
    if (this.proximaPilha.proximaPilha == null) {
      T removido = this.processoAtual;
      this.processoAtual = null;
      this.proximaPilha = null;
      return removido;
    } else {
      return this.proximaPilha.removerPilha();
    }
  }

  public boolean vaziaPilha() {
    return this.proximaPilha == null;
  }}
