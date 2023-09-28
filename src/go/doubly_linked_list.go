package main

import (
	"reflect"
	"testing"
)

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

func TestDoublyLinkedList(t *testing.T) {
	list := DoublyLinkedList{}

	// test AddLeft
	list.AddLeft(1)
	list.AddLeft(2)
	if !reflect.DeepEqual(list.ToSlice(), []int{2, 1}) {
		t.Errorf("AddLeft failed, expected %v, got %v", []int{2, 1}, list.ToSlice())
	}

	// test AddRight
	list.AddRight(3)
	list.AddRight(4)
	if !reflect.DeepEqual(list.ToSlice(), []int{2, 1, 3, 4}) {
		t.Errorf("AddRight failed, expected %v, got %v", []int{2, 1, 3, 4}, list.ToSlice())
	}

	//// test RemoveLeft
	list.RemoveLeft()
	if !reflect.DeepEqual(list.ToSlice(), []int{1, 3, 4}) {
		t.Errorf("RemoveLeft failed, expected %v, got %v", []int{1, 3, 4}, list.ToSlice())
	}

	// test RemoveRight
	list.RemoveRight()
	if !reflect.DeepEqual(list.ToSlice(), []int{1, 3}) {
		t.Errorf("RemoveRight failed, expected %v, got %v", []int{1, 3}, list.ToSlice())
	}

	// test AddAt
	list.AddAt(1, 5)
	if !reflect.DeepEqual(list.ToSlice(), []int{1, 5, 3}) {
		t.Errorf("AddAt failed, expected %v, got %v", []int{1, 5, 3}, list.ToSlice())
	}

	// test RemoveAt
	list.RemoveAt(2)
	if !reflect.DeepEqual(list.ToSlice(), []int{1, 5}) {
		t.Errorf("RemoveAt failed, expected %v, got %v", []int{1, 5}, list.ToSlice())
	}

	// test FindAt
	node := list.FindAt(0)
	if node == nil || node.Value != 1 {
		t.Errorf("FindAt failed, expected %v, got %v", 1, node.Value)
	}
}
