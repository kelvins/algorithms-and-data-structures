
public class No {
	int chave;
	No esq, dir;
	public No(int chave){
		this.chave = chave;
		this.esq = null;
		this.dir = null;
	}
	public int getChave() {
		return chave;
	}
	public void setChave(int chave) {
		this.chave = chave;
	}
	public No getEsq() {
		return esq;
	}
	public void setEsq(No esq) {
		this.esq = esq;
	}
	public No getDir() {
		return dir;
	}
	public void setDir(No dir) {
		this.dir = dir;
	}
	
}
