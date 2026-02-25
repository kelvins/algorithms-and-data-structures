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

function main {
  let deque = new Deque();

  deque.addFront(2);
  deque.addFront(1);
  deque.addFront(0);

  deque.addEnd(3);
  deque.addEnd(4);

  deque.removeFront();
  deque.removeEnd();

  deque.readFromFront();
  deque.readFromEnd();
}

main();
