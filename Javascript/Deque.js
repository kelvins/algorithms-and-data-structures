class Deque{
    constructor(){
        this.deque = [];
    }

    addInicio(valor){
        this.deque.unshift(valor);
    }

    addFim(valor){
        this.deque.push(valor);
    }

    removeInicio(){
        this.deque.shift();
    }

    removeFim(){
        this.deque.pop();
    }

    lerDoInicio(){
        console.log(this.deque);
    }

    lerDoFim(){
        let dequeCopia = this.deque.slice();
        console.log(dequeCopia.reverse());
    }
}