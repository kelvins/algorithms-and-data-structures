import java.util.Objects;

class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
        this.next = null;
    }

    Node(int val, Node next) {
        this.val = val;
        this.next = next;
    }
}

public class SinglyLinkedList {
    Node head;

    public void printList() {
        Node aux = head;
        System.out.print("[");
        while (aux != null) {
            System.out.print(aux.val);
            if (aux.next != null) {
                System.out.print(", ");
            }
            aux = aux.next;
        }
        System.out.println("]");
    }

    public void pushBack(int val) {
        Node newNode = new Node(val);
        if (head == null) {
            head = newNode;
        } else {
            Node aux = head;
            while (aux.next != null) {
                aux = aux.next;
            }
            aux.next = newNode;
        }
    }

    public void pushFront(int val) {
        Node newNode = new Node(val, head);
        head = newNode;
    }

    public void insertInPosition(int val, int pos) {
        if (pos == 0) {
            pushFront(val);
            return;
        }
        Node newNode = new Node(val);
        Node prev = head;
        Node curr = head;

        while (curr != null && pos > 0) {
            prev = curr;
            curr = curr.next;
            pos--;
        }

        prev.next = newNode;
        newNode.next = curr;
    }

    public void popBack() {
        if (head == null) {
            return;
        }

        if (head.next == null) {
            head = null;
            return;
        }

        Node prev = head;
        Node curr = head.next;

        while (curr.next != null) {
            prev = prev.next;
            curr = curr.next;
        }

        prev.next = null;
    }

    public void popFront() {
        if (head == null) {
            return;
        }

        Node aux = head;
        head = aux.next;
    }

    public void removeFromPosition(int pos) {
        if (head == null) {
            return;
        }

        if (pos == 0) {
            popFront();
            return;
        }

        Node prev = head;
        Node curr = head;

        while (curr != null && pos > 0) {
            prev = curr;
            curr = curr.next;
            pos--;
        }

        if (curr != null) {
            prev.next = curr.next;
        }
    }

    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();

        System.out.println("Inserting the elements at the end [1, 2, 3]:");
        list.pushBack(1);
        list.pushBack(2);
        list.pushBack(3);
        list.printList();

        System.out.println("Inserting the elements at the beginning [0, -1, -2]:");
        list.pushFront(0);
        list.pushFront(-1);
        list.pushFront(-2);
        list.printList();

        System.out.println("Inserting in positions 3, 4, 5 the elements [997, 998, 999] respectively:");
        list.insertInPosition(997, 3);
        list.insertInPosition(998, 4);
        list.insertInPosition(999, 5);
        list.printList();

        System.out.println("Removing last element:");
        list.popBack();
        list.printList();

        System.out.println("Removing first element:");
        list.popFront();
        list.printList();

        System.out.println("Removing element in position 2:");
        list.removeFromPosition(2);
        list.printList();
    }
}

