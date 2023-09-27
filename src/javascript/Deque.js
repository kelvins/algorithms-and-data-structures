class Deque {
    constructor() {
        this.deque = [];
    }

        addFront(value) {
        this.deque.unshift(value);
    }

    addEnd(value) {
        this.deque.push(value);
    }

    removeFront() {
        this.deque.shift();
    }

    removeEnd() {
        this.deque.pop();
    }

    readFromFront() {
        console.log(this.deque);
    }

    readFromEnd() {
        let dequeCopy = this.deque.slice();
        console.log(dequeCopy.reverse());
    }
}