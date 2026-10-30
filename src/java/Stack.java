public class stack {

  public processo processoAtual;
  public stack proximaPilha;

  public stack() {
    this.processoAtual = null;
    this.proximaPilha = null;
  }

  public void inserirpilha(processo processoNovo) {
    if (this.processoAtual == null) {
      this.processoAtual = processoNovo;
      this.proximaPilha = new stack();
    } else {
      this.proximaPilha.inserirpilha(processoNovo);
    }
  }

  public processo removerPilha() {
    if (this.proximaPilha.proximaPilha == null) {
      processo removido = this.processoAtual;
      this.processoAtual = null;
      this.proximaPilha = null;
      return removido;
    } else {
      return this.proximaPilha.removerPilha();
    }
  }

  public String checkpilha(String empty) {
    if (this.proximaPilha.proximaPilha == null) {
      empty =
          " " + this.processoAtual.getPrioridade() + " " + this.processoAtual.getTempo() + empty;
    } else {
      empty =
          this.proximaPilha.checkpilha(empty)
              + " && "
              + this.processoAtual.getPrioridade()
              + " "
              + this.processoAtual.getTempo()
              + " "
              + empty;
    }
    return empty;
  }

  public boolean vaziaPilha() {
    if (this.proximaPilha == null) {
      return true;
    }
    return false;
  }

  public int tempoTrabalhado(int tempo) {
    return this.processoAtual.trabalhado(tempo);
  }
}
