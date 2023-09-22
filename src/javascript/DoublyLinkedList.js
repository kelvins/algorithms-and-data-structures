class DoublyListNode {
    constructor(value, previous, next) {
        this.value = value;
        this.next = next;
        this.previous = previous;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    addToFront(value) {
        let newNode = new DoublyListNode(value, null, this.head);

        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.head.previous = newNode;
            this.head = newNode;
        }
    }

    addToEnd(value) {
        let newNode = new DoublyListNode(value, this.tail, null);

        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
    }

    remove(value) {
        if (this.head === null) {
            return;
        }

        if (this.head.value === value) {
            this.head = this.head.next;
            if (this.head !== null) {
                this.head.previous = null;
            }
        } else if (this.tail.value === value) {
            this.tail = this.tail.previous;
            if (this.tail !== null) {
                this.tail.next = null;
            }
        } else {
            let currentNode = this.head;
            let nodeToDelete = null;

            while (currentNode.next !== null) {
                if (currentNode.next.value === value) {
                    nodeToDelete = currentNode.next;
                    currentNode.next = currentNode.next.next;
                    if (currentNode.next !== null) {
                        currentNode.next.previous = currentNode;
                    }
                    break;
                }
                currentNode = currentNode.next;
            }

            if (nodeToDelete === null) {
                console.log("Value not found");
            }
        }
    }

    readFromFront() {
        if (this.head === null) {
            console.log("Empty");
            return;
        }

        let currentNode = this.head;

        console.log("Reading from the Front");
        while (currentNode !== null) {
            console.log(currentNode.value);
            currentNode = currentNode.next;
        }
    }

    readFromEnd() {
        if (this.head === null) {
            console.log("Empty");
            return;
        }

        let currentNode = this.tail;

        console.log("Reading from the End");
        while (currentNode !== null) {
            console.log(currentNode.value);
            currentNode = currentNode.previous;
        }
    }
}
