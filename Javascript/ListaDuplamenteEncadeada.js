class NoListaDE{
    constructor(valor, anterior, proximo){
        this.valor = valor;
        this.proximo = proximo;
        this.anterior = anterior;
    }
}

class ListaDuplamenteEncadeada{
    constructor(){
        this.cabeca = null;
        this.calda = null;
    }

    addInicio(valor){
        let novoNo = new NoListaDE(valor, null, this.cabeca);

        if(this.cabeca == null){
            this.cabeca = novoNo;
            this.calda = novoNo;
        } else {
            this.cabeca.anterior = novoNo;
            this.cabeca = novoNo;
        }
    }

    addFim(valor){
        let novoNo = new NoListaDE(valor, this.calda, null);

        if(this.cabeca == null){
            this.cabeca = novoNo;
            this.calda = novoNo;
        } else {
            this.calda.proximo = novoNo;
            this.calda = novoNo;
        }
    }

    remover(valor){
        if(this.cabeca == null){
            return;
        }

        if(this.cabeca.valor == valor){
            
            this.cabeca = this.cabeca.proximo;
            this.cabeca.anterior = null;

        } else if(this.calda.valor == valor){

            this.calda = this.calda.anterior;
            this.calda.proximo = null;

        } else {

            let noAtual = this.cabeca;
            let noPorDeletar = null;

            while(noAtual.proximo != null){
                if(noAtual.proximo.valor == valor){
                    noPorDeletar = noAtual.proximo;
                    noAtual.proximo = noAtual.proximo.proximo;
                    noAtual.proximo.proximo.anterior = noAtual;
                    break;
                }
                noAtual = noAtual.proximo;
            }

            if(noPorDeletar == null){
                console.log("Valor não encontrado");
            }

        }
    }

    lerDoInicio(){
        if(this.cabeca == null){
            console.log("Vazio");
            return;
        }

        let noAtual = this.cabeca;

        console.log("Lendo do Inicio");
        while(noAtual != null){
            console.log(noAtual.valor);
            noAtual = noAtual.proximo;
        }
    }

    lerDoFim(){
        if(this.cabeca == null){
            console.log("Vazio");
            return;
        }

        let noAtual = this.calda;

        console.log("Lendo do Fim");
        while(noAtual != null){
            console.log(noAtual.valor);
            noAtual = noAtual.anterior;
        }
    }
}