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

function main() {
  let stack = new Stack();

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.read();

  stack.pop();
  stack.read();

  stack.clear();
  stack.read();
}

main();
