package main

import "fmt"

// A simple stack using generics
type Stack[T any] struct {
	items []T
}

func (stack *Stack[T]) Push(value T) {
	stack.items = append(stack.items, value)
}

func (stack *Stack[T]) Pop() T {
	n := len(stack.items)
	if n <= 0 {
		panic("Cannot pop an empty stack!")
	}
	value := stack.items[n-1]
	stack.items = stack.items[:n-1]
	return value
}

func (stack *Stack[T]) Show() {
	fmt.Printf("%v\n", stack.items)
}

func main() {
	stack := Stack[int]{}
	stack.Push(1)
	stack.Push(2)
	stack.Push(3)
	stack.Push(4)
	stack.Pop()
	fmt.Printf("Stack: ")
	stack.Show()
}
