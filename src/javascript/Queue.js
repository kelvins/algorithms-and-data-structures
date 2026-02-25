class Queue {
    constructor() {
        this.queue = [];
    }

    enqueue(value) {
        this.queue.push(value);
    }

    dequeue() {
        this.queue.shift(0);
    }

    read() {
        console.log(this.queue);
    }

    empty() {
        this.queue = [];
    }
}

function main() {
  let queue = new Queue();

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.read();

  queue.dequeue();
  queue.read();

  queue.empty();
  queue.read();
}

main();
