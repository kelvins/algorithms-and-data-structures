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