import java.util.Objects;

public class ListaEncadeada {

    public static void main(String[] args) {

        LinkedList list = new LinkedList();

        list.add("1");
        list.add("2");
        list.add("3");
        list.add("4");

        System.out.println(list.get(3));

        list.add(3, "3.5");

        System.out.println(list.get(3));

        System.out.println("size: " + list.size());

        list.remove(0);

        System.out.println(list.get(0));

        System.out.println("size: " + list.size());

        list.remove(3);

        System.out.println("size: " + list.size());

        //posição invalida
        //System.out.println(list.get(3));

        System.out.println(list.contains("2"));



    }

}

class Node {

    private final Object element;

    private Node next;

    public Node(Object element, Node node) {
        this.element = element;
        this.next = node;
    }

    public Object getElement() {
        return this.element;
    }

    public Node getNext() {
        return this.next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    @Override
    public String toString() {
        return element.toString();
    }

    @Override
    public boolean equals(Object o) {
        return this.getElement().equals(o);
    }

    @Override
    public int hashCode() {
        return Objects.hash(element);
    }
}

class LinkedList {

    private Node first = null;

    private Node last = null;

    private Integer total = 0;

    private void addAtBeginning(Object element) {

        this.first = new Node(element, this.first);

        if(this.total == 0) {
            this.last = this.first;
        }

        this.total++;
    }

    public void add(Object element) {

        if(this.total == 0) {
            this.addAtBeginning(element);
        } else {

            Node newElement = new Node(element, null);

            this.last.setNext(newElement);

            this.last = newElement;

            this.total++;

        }
    }

    public void add(int position, Object element) {

        if(this.total == 0) {
            this.addAtBeginning(element);
        } else if (this.total == position) {
            this.add(element);
        } else {

            Node previus = this.getElementInPosition(position - 1);

            Node newElement = new Node(element, previus.getNext());

            previus.setNext(newElement);

            this.total++;

        }

    }

    private boolean occupiedPosition(Integer position) {
        return position < 0 && position >= this.total;
    }

    private Node getElementInPosition(int position) {

        if(this.occupiedPosition(position)) {
            throw new IllegalArgumentException("invalid position");
        }

        Node current = this.first;

        for (int i = 0; i < position; i++) {
            current = current.getNext();
        }

        return current;

    }

    public Object get(int position) {

        return this.getElementInPosition(position).getElement();

    }

    private void removeAtBeginning() {

        if (this.total == 0) {
            throw new IllegalArgumentException("empty list");
        }

        this.first = this.first.getNext();

        this.total--;

        if (this.total == 0) {
            this.last = null;
        }

    }

    public void remove(int position) {

        if (position == 0) {
            this.removeAtBeginning();
        } else {

            Node previus = this.getElementInPosition(position - 1);

            Node element = this.getElementInPosition(position);

            previus.setNext(element.getNext());

            this.total--;

        }

    }

    public int size() {
        return this.total;
    }

    public boolean contains(Object object) {

        Node current = this.first;

        while (current.getNext() != null) {

            if(current.getElement().equals(object)) {
                return true;
            }

            current = current.getNext();

        }

        return false;

    }

}
