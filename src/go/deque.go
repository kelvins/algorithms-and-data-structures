package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

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

func TestDeque(t *testing.T) {
	deque := Deque{}

	deque.RPush(1)
	deque.RPush(2)
	deque.RPush(3)

	assert.Equal(t, 3, *deque.RPop())
	assert.Equal(t, 2, *deque.RPop())
	assert.Equal(t, 1, *deque.RPop())
	assert.Nil(t, deque.RPop())

	deque.LPush(1)
	deque.LPush(2)
	deque.LPush(3)

	assert.Equal(t, 1, *deque.RPop())
	assert.Equal(t, 2, *deque.RPop())
	assert.Equal(t, 3, *deque.RPop())
	assert.Nil(t, deque.RPop())
}
