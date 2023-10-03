package main

import "fmt"

type Deque struct {
	Store []int
}

// Time complexity: O(1)
func (deque *Deque) RPush(element int) {
	deque.Store = append(deque.Store, element)
}

// Time complexity: O(n)
func (deque *Deque) LPush(element int) {
	deque.Store = append([]int{element}, deque.Store...)
}

// Time complexity: O(1)
func (deque *Deque) RPop() *int {
	if len(deque.Store) == 0 {
		return nil
	}

	element := deque.Store[len(deque.Store)-1]
	deque.Store = deque.Store[:len(deque.Store)-1]

	return &element
}

// Time complexity: O(n)
func (deque *Deque) LPop() *int {
	if len(deque.Store) == 0 {
		return nil
	}

	element := deque.Store[0]
	deque.Store = deque.Store[1:]

	return &element
}

func main() {
	deque := Deque{}

	fmt.Println("RPush(1, 2, 3)")

	deque.RPush(1)
	deque.RPush(2)
	deque.RPush(3)

	fmt.Println("RPop(): ", *deque.RPop())
	fmt.Println("RPop(): ", *deque.RPop())
	fmt.Println("RPop(): ", *deque.RPop())

	fmt.Println("LPush(1, 2, 3)")

	deque.LPush(1)
	deque.LPush(2)
	deque.LPush(3)

	fmt.Println("RPop(): ", *deque.RPop())
	fmt.Println("RPop(): ", *deque.RPop())
	fmt.Println("RPop(): ", *deque.RPop())
}
