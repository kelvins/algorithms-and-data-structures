class NoFila{
    constructor(valor, proximo){
        this.valor = valor;
        this.proximo = proximo;
    }
}

class Fila{
    constructor(){
        this.cabeça = null;
        this.calda = null;
    }

    add(valor){
        let novoNo = new NoFila(valor, null);

        if(this.cabeça == null){
            this.cabeça = novoNo;
            this.calda = novoNo;
        } else {
            this.calda.proximo = novoNo;
            this.calda = novoNo;
        }
    }

    remove(){
        if(this.cabeça == null){
            console.log("Fila Vazia");
        } else {
            this.cabeça = this.cabeça.proximo;
        }
    }

    ler(){
        let noAtual = this.cabeça;
        console.log("Lendo Fila")
        while(noAtual != null){
            console.log(noAtual.valor);
        }
    }

    esvaziar(){
        console.log("Evaziando");
        this.cabeça = null;
    }
}