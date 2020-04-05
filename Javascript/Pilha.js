class Pilha{
    constructor(){
        this.pilha = [];
    }

    empilhar(valor){
        this.pilha.push(valor);
    }

    desenpilhar(){
        this.pilha.pop(valor);
    }

    ler(){
        console.log(this.pilha);
    }

    esvaziar(){
        this.pilha = [];
    }
}