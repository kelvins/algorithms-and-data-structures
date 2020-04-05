class NoListaSE{
    constructor(valor, proximo){
        this.valor = valor;
        this.proximo = proximo;
    }
}

class ListaSimplesmenteEncadeada{
    constructor(){
        this.cabeca = null;
        this.calda = null;
    }

    addInicio(valor){
        let novoNo = new NoListaSE(valor, this.cabeca);
        
        if(this.cabeca == null){
            this.cabeca = novoNo;
            this.calda = novoNo;
        } else{
            this.cabeca = novoNo;
        }        
    }

    addFim(valor){
        let novoNo = new NoListaSE(valor, null);

        if(this.cabeca == null){
            this.cabeca = novoNo;
            this.calda = novoNo;
        } else {
            this.calda.proximo = novoNo;
            this.calda = novoNo;
        }
    }

    remove(valor){

        if(this.cabeca == null){
            return;
        }

        if(this.cabeca.valor == valor){
            
            this.cabeca = this.cabeca.proximo;

        } else {

            let noAtual = this.cabeca;
            let noPorDeletar = null;

            while(noAtual.proximo != null){
                if(noAtual.proximo.valor == valor){
                    noPorDeletar = noAtual.proximo;
                    noAtual.proximo = noAtual.proximo.proximo;
                    break;
                }
                noAtual = noAtual.proximo;
            }

            if(noPorDeletar == null){
                console.log("Valor não encontrado");
            }

        }

    }

    ler(){
        if(this.cabeca == null){
            console.log("Vazio");
            return;
        }
    
        let noAtual = this.cabeca;

        console.log("Listando");
        while(noAtual != null){

            console.log(noAtual.valor);

            noAtual = noAtual.proximo;
        }
    }

}
