package main

import "fmt"

type Node struct {
	Value int
	Next  *Node
	Prev  *Node
}

type DoublyLinkedList struct {
	Head *Node
	Tail *Node
}

func (list *DoublyLinkedList) AddLeft(value int) {
	node := Node{Value: value}

	if list.Head == nil {
		list.Head = &node
		list.Tail = &node
		return
	}

	node.Next = list.Head
	list.Head.Prev = &node
	list.Head = &node
}

func (list *DoublyLinkedList) AddRight(value int) {
	node := Node{Value: value}

	if list.Tail == nil {
		list.Tail = &node
		list.Head = &node
		return
	}

	node.Prev = list.Tail
	list.Tail.Next = &node
	list.Tail = &node
}

func (list *DoublyLinkedList) RemoveLeft() {
	if list.Head == nil {
		return
	}

	list.Head = list.Head.Next

	if list.Head != nil {
		list.Head.Prev = nil
	} else {
		list.Tail = nil
	}
}

func (list *DoublyLinkedList) RemoveRight() {
	if list.Tail == nil {
		return
	}

	list.Tail = list.Tail.Prev

	if list.Tail != nil {
		list.Tail.Next = nil
	} else {
		list.Head = nil
	}
}

func (list *DoublyLinkedList) FindAt(idx int) *Node {
	pointer := list.Head

	for i := 0; i < idx; i++ {
		pointer = pointer.Next
		if pointer == nil {
			return nil
		}
	}

	return pointer
}

func (list *DoublyLinkedList) AddAt(idx, value int) {
	if idx == 0 {
		list.AddLeft(value)
		return
	}

	foundNode := list.FindAt(idx)
	if foundNode == nil {
		return
	}

	prevNode := foundNode.Prev
	if prevNode == nil {
		return
	}

	newNode := Node{Value: value}

	newNode.Prev = prevNode
	newNode.Next = foundNode

	prevNode.Next = &newNode
	foundNode.Prev = &newNode
}

func (list *DoublyLinkedList) RemoveAt(idx int) {
	if idx == 0 {
		list.RemoveLeft()
		return
	}

	foundNode := list.FindAt(idx)
	if foundNode == nil {
		return
	}

	prevNode := foundNode.Prev
	if prevNode == nil {
		return
	}

	prevNode.Next = foundNode.Next

	if foundNode.Next == nil {
		list.Tail = prevNode
		return
	}

	foundNode.Next.Prev = prevNode
}

func (list *DoublyLinkedList) ToSlice() []int {
	var slice []int

	for pointer := list.Head; pointer != nil; pointer = pointer.Next {
		slice = append(slice, pointer.Value)
	}

	return slice
}

func main() {
	list := DoublyLinkedList{}

	fmt.Println("AddLeft(1, 2)")
	list.AddLeft(1)
	list.AddLeft(2)

	fmt.Println("list.toSlice(): ", list.ToSlice())

	fmt.Println("AddRight(3, 4)")
	list.AddRight(3)
	list.AddRight(4)

	fmt.Println("list.toSlice(): ", list.ToSlice())

	fmt.Println("RemoveLeft()")
	list.RemoveLeft()

	fmt.Println("list.toSlice(): ", list.ToSlice())

	fmt.Println("RemoveRight()")
	list.RemoveRight()

	fmt.Println("list.toSlice(): ", list.ToSlice())

	fmt.Println("AddAt(1, 5)")
	list.AddAt(1, 5)

	fmt.Println("list.toSlice(): ", list.ToSlice())

	fmt.Println("RemoveAt(2)")
	list.RemoveAt(2)

	fmt.Println("list.toSlice(): ", list.ToSlice())

	fmt.Println("FindAt(0)")
	node := list.FindAt(0)
	fmt.Println("node.Value: ", node.Value)
}
