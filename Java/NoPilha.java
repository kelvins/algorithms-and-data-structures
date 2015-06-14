
public class NoPilha {
	int chave;
	NoPilha prox;
	
	public NoPilha(int chave){
		this.chave = chave;
	}
	
	public int getChave() {
		return chave;
	}

	public void setChave(int chave) {
		this.chave = chave;
	}

	public NoPilha getProx() {
		return prox;
	}

	public void setProx(NoPilha prox) {
		this.prox = prox;
	}
	
}
