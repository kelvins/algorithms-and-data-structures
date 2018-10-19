
public class pilha {

	public processo processoAtual;
	public pilha proximaPilha;
	
	public pilha() {
		this.processoAtual = null;
		this.proximaPilha = null;
	}
	
	public void inserirpilha(processo processoNovo) {
		if(this.processoAtual == null) {
			this.processoAtual = processoNovo;
			this.proximaPilha = new pilha();
		} else {
			this.proximaPilha.inserirpilha(processoNovo);
		}
	}

	public processo removerPilha() {
		if(this.proximaPilha.proximaPilha == null) {
			processo removido = this.processoAtual;
			this.processoAtual = null;
			this.proximaPilha = null;
			return removido;
		} else {
			return this.proximaPilha.removerPilha();
		}
	}
	
	public String checkpilha(String vazia) {
		if(this.proximaPilha.proximaPilha == null) {
			vazia = " " + this.processoAtual.getPrioridade() + " "  + this.processoAtual.getTempo() + vazia;
		} else {
			vazia = this.proximaPilha.checkpilha(vazia)+ " && " + this.processoAtual.getPrioridade() + " "  + this.processoAtual.getTempo() + " " + vazia;
		}
		return vazia;
	}
	
	public boolean vaziaPilha() {
		if(this.proximaPilha == null) {
			return true;
		}
		return false;
	}

	public int tempoTrabalhado(int tempo) {
		return this.processoAtual.trabalhado(tempo);
	}
}
