
// javac ListaDuplamenteEncadeada.java
// java ListaDuplamenteEncadeada

public class ListaDuplamenteEncadeada {

	public static void main(String[] args) {
		LinkedList linkedList = new LinkedList();
		
		linkedList.add(2);
		linkedList.print();
		linkedList.add(5);
		linkedList.print();
		linkedList.add(12);
		linkedList.print();
		linkedList.add(20);
		linkedList.print();

		linkedList.remove(12);
		linkedList.print();
		linkedList.remove(5);
		linkedList.print();
	}

}

class Node {
	
	int data;
	Node prev;
	Node next;
	
	public Node(int data, Node prev, Node next) {
		this.data = data;
		this.prev = prev;
		this.next = next;
	}
	
	public int getData() {
		return data;
	}
	
	public void setData(int data) {
		this.data = data;
	}
	
	public Node getPrev() {
		return prev;
	}
	
	public void setPrev(Node prev) {
		this.prev = prev;
	}
	
	public Node getNext() {
		return next;
	}
	
	public void setNext(Node next) {
		this.next = next;
	}
}

class LinkedList {

	Node head = null;
	Node tail = null;
	
	public void add(int data) {
		Node newNode = new Node(data, null, null);
		
		if(this.head == null) {
			this.head = newNode;
			this.tail = newNode;
		} else {
			newNode.setPrev(this.tail);
			newNode.setNext(null);
			this.tail.setNext(newNode);
			this.tail = newNode;
		}
	}
	
	public void remove(int data) {
		Node currentNode = this.head;
		
		while(currentNode != null) {
			if(currentNode.getData() == data) {
				if(currentNode.getPrev() == null) {
					this.head = currentNode.getNext();
					currentNode.getNext().setPrev(null);
				} else {
					currentNode.getPrev().setNext(currentNode.getNext());
					currentNode.getNext().setPrev(currentNode.getPrev());
				}
			}
			currentNode = currentNode.getNext();
		}
	}
	
	public void print() {
		System.out.println("Doubly Linked List");
		
		Node currentNode = this.head;
		
		while(currentNode != null) {
			if(currentNode.getPrev() == null) {
				System.out.print("None ");
			}
			System.out.print("<---> | " + currentNode.getData() + " | ");
			if(currentNode.getNext() == null) {
				System.out.print("<---> None");
			}
			currentNode = currentNode.getNext();
		}
		
		System.out.println("\n===================================================");
	}
}