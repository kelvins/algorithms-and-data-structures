public class queue {

  public processo processoAtual;
  public queue proximaFila;

  public queue() {
    this.processoAtual = null;
    this.proximaFila = null;
  }

  public void inserirfila(processo processoNovo) {
    if (this.processoAtual == null) {
      this.processoAtual = processoNovo;
      this.proximaFila = new queue();
    } else {
      this.proximaFila.inserirfila(processoNovo);
    }
  }

  public processo removerfila() {
    processo removido = this.processoAtual;
    this.processoAtual = this.proximaFila.processoAtual;
    this.proximaFila = this.proximaFila.proximaFila;
    return removido;
  }

  public String checkfila(String empty) {
    if (this.proximaFila.proximaFila == null) {
      empty =
          empty + " " + this.processoAtual.getPrioridade() + " " + this.processoAtual.getTempo();
    } else {
      empty =
          empty
              + " "
              + this.processoAtual.getPrioridade()
              + " "
              + this.processoAtual.getTempo()
              + " &&"
              + this.proximaFila.checkfila(empty);
    }
    return empty;
  }

  public boolean vaziafila() {
    if (this.proximaFila == null) {
      return true;
    }
    return false;
  }
}
