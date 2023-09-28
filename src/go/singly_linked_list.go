package main

import (
	"reflect"
	"testing"
)

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

func TestSinglyLinkedList(t *testing.T) {
	list := SinglyLinkedList{}

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
