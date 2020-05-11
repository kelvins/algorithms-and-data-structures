class NoArvoreBinaria{
    constructor(valor, esquerda, direita){
        this.valor = valor;
        this.esquerda = esquerda;
        this.direita = direita;
    }
}

class ArvoreDeBuscaBinaria{
    constructor(){
        this.raiz = null;
    }

    add(valor){
        let novoNo = new NoArvoreBinaria(valor, null, null);

        if(this.raiz == null)
            this.raiz = novoNo;

        else {
            let auxiliar = this.raiz;
            let encontrado = false;

            while(!encontrado){
                if(novoNo.valor < auxiliar.valor){
                    if(auxiliar.esquerda == null){
                        auxiliar.esquerda = novoNo;
                        encontrado = true;
                    } else {
                        auxiliar = auxiliar.esquerda;
                    }

                } else {
                    if(auxiliar.direita == null){
                        auxiliar.direita = novoNo;
                        encontrado = true;
                    } else {
                        auxiliar = auxiliar.direita;
                    }
                }
            }
        }
    }

    remove(valor){
        let auxiliar = this.raiz
        let encontrado = false;

        if(valor != this.raiz.valor){
            let anterior = this.raiz;

            while(auxiliar != null && !encontrado){
                if(valor == auxiliar.valor){
                    encontrado = true;
                } else if(valor < auxiliar.valor){
                    anterior = auxiliar;
                    auxiliar = auxiliar.esquerda;
                } else {
                    anterior = auxiliar;
                    auxiliar = auxiliar.direita;
                }
            }

            if(auxiliar == null){
                console.log("Elemento não existe");
                return;
            }

            if(auxiliar.direita == null && auxiliar.esquerda == null){
                if(anterior.esquerda == auxiliar) anterior.esquerda = null;
                else anterior.direita = null;
                
            } else if(auxiliar.direita != null && auxiliar.esquerda == null){
                if(anterior.esquerda == auxiliar) anterior.esquerda = auxiliar.direita;
                else anterior.direita = auxiliar.direita;

            } else if(auxiliar.direita == null && auxiliar.esquerda != null){
                if(anterior.esquerda == auxiliar) anterior.esquerda = auxiliar.esquerda;
                else anterior.direita = auxiliar.esquerda;

            } else {
                let noDireitaElementoEscluido = auxiliar.direita;
                let noEsquerdaElementoEscluido = auxiliar.esquerda;
                let anteriorDoAuxiliar;

                if(auxiliar == anterior.direita){
                    auxiliar = auxiliar.esquerda;
                    while(auxiliar.direita != null){
                        anteriorDoAuxiliar = auxiliar;
                        auxiliar = auxiliar.direita;
                    }
                    anterior.direita = auxiliar;

                } else {
                    auxiliar = auxiliar.esquerda;
                    while(auxiliar.direita != null){
                        anteriorDoAuxiliar = auxiliar;
                        auxiliar = auxiliar.direita;
                    }
                    anterior.esquerda = auxiliar;

                }

                auxiliar.direita = noDireitaElementoEscluido;
                auxiliar.esquerda = noEsquerdaElementoEscluido;
                anteriorDoAuxiliar.direita = null;
            }

        } else {
            if(auxiliar.direita == null && auxiliar.esquerda == null) {
                this.raiz = null;
            } else {
                if (auxiliar.esquerda != null && auxiliar.direita == null) 
                    this.raiz = auxiliar.esquerda;
                else if (auxiliar.esquerda == null && auxiliar.direita != null)
                    this.raiz = auxiliar.direita;
                else if (auxiliar.esquerda != null && auxiliar.direita != null) {
                    let noDireitaElementoEscluido = this.raiz.direita;
                    let noEsquerdaElementoEscluido = this.raiz.esquerda;
                    let anteriorDoAuxiliar;
                        
                    auxiliar = this.raiz.esquerda;
                    while(auxiliar.direita != null) {	
                        anteriorDoAuxiliar = auxiliar;
                        auxiliar = auxiliar.direita;
                    }
                    this.raiz = auxiliar;
                        
                    auxiliar.direita = noDireitaElementoEscluido;
                    auxiliar.esquerda = noEsquerdaElementoEscluido;
                    anteriorDoAuxiliar.direita = null;
                }
            }

        }
    }

    verificaElemento(valor){
        let auxiliar = this.raiz;
        encontrado = false;

        while(auxiliar != null && !encontrado){
            if(valor == auxiliar.valor) encontrado = true; 
            else if (valor < auxiliar.valor) auxiliar = auxiliar.esquerda;
            else if (valor > auxiliar.valor) auxiliar = auxiliar.direita;
        }

        if(encontrado) console.log("Elemento Presente");
        else console.log("Elemento Não Encontrado");
    }

    consultaPreOrdem(raiz = this.raiz){
        let auxiliar = raiz;

        console.log(auxiliar.valor);
        if(auxiliar.esquerda != null) this.consultaPreOrdem(auxiliar.esquerda);
        if(auxiliar.direita != null) this.consultaPreOrdem(auxiliar.direita);
    }

    consultaPosOrdem(raiz = this.raiz){
        let auxiliar = raiz;

        if(auxiliar.esquerda != null) this.consultaPosOrdem(auxiliar.esquerda);
        if(auxiliar.direita != null) this.consultaPosOrdem(auxiliar.direita);
        console.log(auxiliar.valor);
    }
    
    consultaOrdem(raiz = this.raiz){
        let auxiliar = raiz;

        if(auxiliar.esquerda != null) this.consultaOrdem(auxiliar.esquerda);
        console.log(auxiliar.valor);
        if(auxiliar.direita != null) this.consultaOrdem(auxiliar.direita);
    }

    esvaziar(){
        this.raiz = null;
    }
}

