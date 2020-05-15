class Fila{
    constructor(){
        this.fila = [];
    }

    enfileirar(valor){
        this.fila.push(valor);
    }

    desenfileirar(){
        this.fila.shift(0);
    }

    ler(){
        console.log(this.fila);
    }

    esvaziar(){
        this.fila = [];
    }
}