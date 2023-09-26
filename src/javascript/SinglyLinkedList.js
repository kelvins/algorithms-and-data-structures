// SinglyListNode represents a node in a singly linked list.
class SinglyListNode {
    constructor(value, next) {
        this.value = value;
        this.next = next;
    }
}

// SinglyLinkedList represents a singly linked list data structure.
class SinglyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    addToFront(value) {
        let newNode = new SinglyListNode(value, this.head);

        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.head = newNode;
        }
    }

    addToEnd(value) {
        let newNode = new SinglyListNode(value, null);

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
        } else {
            let currentNode = this.head;
            let nodeToDelete = null;

            while (currentNode.next !== null) {
                if (currentNode.next.value === value) {
                    nodeToDelete = currentNode.next;
                    currentNode.next = currentNode.next.next;
                    break;
                }
                currentNode = currentNode.next;
            }

            if (nodeToDelete === null) {
                console.log("Value not found");
            }
        }
    }

    read() {
        if (this.head === null) {
            console.log("Empty");
            return;
        }

        let currentNode = this.head;

        console.log("Listing");
        while (currentNode !== null) {
            console.log(currentNode.value);
            currentNode = currentNode.next;
        }
    }
}

module.exports = SinglyLinkedList;

