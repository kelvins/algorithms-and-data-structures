package stack

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
