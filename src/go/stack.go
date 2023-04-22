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
	pilha := Stack[int]{}
	pilha.Push(1)
	pilha.Push(2)
	pilha.Push(3)
	pilha.Push(4)
	pilha.Pop()
	fmt.Printf("Stack: ")
	pilha.Show()
}
