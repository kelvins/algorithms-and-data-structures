package main

import "fmt"

type Node struct {
	Value int
	Next  *Node
}

type SinglyLinkedList struct {
	Head *Node
}

func (list *SinglyLinkedList) AddLeft(value int) {
	node := Node{Value: value}

	if list.Head == nil {
		list.Head = &node
		return
	}

	node.Next = list.Head
	list.Head = &node
}

func (list *SinglyLinkedList) AddRight(value int) {
	node := Node{Value: value}

	if list.Head == nil {
		list.Head = &node
		return
	}

	pointer := list.Head

	for pointer.Next != nil {
		pointer = pointer.Next
	}

	pointer.Next = &node
}

func (list *SinglyLinkedList) RemoveLeft() {
	if list.Head == nil {
		return
	}

	list.Head = list.Head.Next
}

func (list *SinglyLinkedList) RemoveRight() {
	if list.Head == nil {
		return
	}

	if list.Head.Next == nil {
		list.Head = nil
		return
	}

	pointer := list.Head

	for pointer.Next.Next != nil {
		pointer = pointer.Next
	}

	pointer.Next = nil
}

func (list *SinglyLinkedList) FindAt(idx int) *Node {
	pointer := list.Head

	for i := 0; i < idx; i++ {
		pointer = pointer.Next
		if pointer == nil {
			return nil
		}
	}

	return pointer
}

func (list *SinglyLinkedList) AddAt(idx, value int) {
	if idx == 0 {
		list.AddLeft(value)
		return
	}

	prevNode := list.FindAt(idx - 1)

	if prevNode == nil {
		return
	}

	node := Node{Value: value}

	node.Next = prevNode.Next
	prevNode.Next = &node
}

func (list *SinglyLinkedList) RemoveAt(idx int) {
	if idx == 0 {
		list.RemoveLeft()
		return
	}

	prevNode := list.FindAt(idx - 1)

	if prevNode == nil {
		return
	}

	prevNode.Next = prevNode.Next.Next
}

func (list *SinglyLinkedList) ToSlice() []int {
	var slice []int

	for pointer := list.Head; pointer != nil; pointer = pointer.Next {
		slice = append(slice, pointer.Value)
	}

	return slice
}

func main() {
	list := SinglyLinkedList{}

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
