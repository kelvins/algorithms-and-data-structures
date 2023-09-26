class Stack {
    constructor() {
        this.stack = [];
    }

    push(value) {
        this.stack.push(value);
    }

    pop() {
        this.stack.pop();
    }

    read() {
        console.log(this.stack);
    }

    clear() {
        this.stack = [];
    }
}