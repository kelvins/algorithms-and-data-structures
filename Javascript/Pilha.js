class NoPilha{
    constructor(valor, proximo){
        this.valor = valor;
        this.proximo = proximo;
    }
}

class Pilha{
    constructor(){
        this.topo = null;
    }

    add(valor){
        let novoNo = new NoPilha(valor, this.topo);

        this.topo = novoNo;
    }

    remove(){
        if(this.topo == null){
            console.log("Pilha Vazia");
        } else {
            this.topo = this.topo.proximo;
        }
    }

    ler(){
        let noAtual = this.topo;

        console.log("Lendo Pilha");
        while(noAtual != null){
            console.log(noAtual.valor);
            noAtual = noAtual.proximo;
        }
    }

    esvaziar(){
        if(this.topo == null){
            console.log("Pilha Vazia");
        } else {
            this.topo = null;
        }
    }
}