public class Queue<T> {

  public T processoAtual;
  public Queue<T> proximaFila;

  public Queue() {
    this.processoAtual = null;
    this.proximaFila = null;
  }

  public void inserirfila(T processoNovo) {
    if (this.processoAtual == null) {
      this.processoAtual = processoNovo;
      this.proximaFila = new Queue<>();
    } else {
      this.proximaFila.inserirfila(processoNovo);
    }
  }

  public T removerfila() {
    T removido = this.processoAtual;
    this.processoAtual = this.proximaFila.processoAtual;
    this.proximaFila = this.proximaFila.proximaFila;
    return removido;
  }

  public boolean vaziafila() {
    if (this.proximaFila == null) {
      return true;
    }
    return false;
  }
}
