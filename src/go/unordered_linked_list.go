/*
* Lists - Unordered linear list
*
* Implementation of a sequential list where elements are not ordered
*
* Go Playground link: https://play.golang.org/p/3uFOquVlTD8
 */

package main

import "fmt"

var maxSize = 50

// Structure that will be stored in each position of the list
type Record struct {
	value int
	// Other fields can be added here
}

// Structure that holds an array of Records and the number of elements in the array
type List struct {
	recordArray      []Record
	numberOfElements int
}

// Creates a new list
func createList() List {
	list := List{
		recordArray:      make([]Record, maxSize),
		numberOfElements: 0,
	}

	return list
}

// Resets the list's element counter
func initialize(list *List) {
	list.numberOfElements = 0
}

// Retrieves the number of elements in the list
func size(list *List) int {
	return list.numberOfElements
}

// Prints the values of the elements in the list
func print(list *List) {
	for i := 0; i < list.numberOfElements; i++ {
		fmt.Printf("%v ", list.recordArray[i].value)
	}
	fmt.Println()
}

// Performs a sequential search in the list, iterating through each item
func sequentialSearch(list *List, value int) int {
	i := 0
	for i < list.numberOfElements {
		if value == list.recordArray[i].value {
			return i
		}
		i++
	}
	return -1
}

// Performs a sentinel search in the list, iterating through each item
func sentinelSearch(list *List, value int) int {
	i := 0
	list.recordArray[list.numberOfElements].value = value

	for value != list.recordArray[i].value {
		i++
	}

	if i == list.numberOfElements {
		return -1
	}
	return i
}

// Inserts elements into the list at a specific position and moves all other elements to the right
func insertElement(list *List, record Record, position int) bool {
	if (list.numberOfElements == maxSize) || position < 0 || position > list.numberOfElements {
		return false
	}

	for j := list.numberOfElements; j > position; j-- {
		list.recordArray[j] = list.recordArray[j-1]
	}

	list.recordArray[position] = record
	list.numberOfElements++

	return true
}

// Deletes an element from the list
func deleteElement(list *List, value int) bool {
	position := sequentialSearch(list, value)

	if position == -1 {
		return false
	}

	for i := position; i < list.numberOfElements-1; i++ {
		list.recordArray[i] = list.recordArray[i+1]
	}

	list.numberOfElements--

	return true
}

func main() {
	list := createList()

	initialize(&list)

	fmt.Println("Inserting values into the list...")
	insertElement(&list, Record{value: 20}, 0)
	insertElement(&list, Record{value: 10}, 0)
	insertElement(&list, Record{value: 70}, 0)
	insertElement(&list, Record{value: 30}, 0)
	insertElement(&list, Record{value: 60}, 0)
	insertElement(&list, Record{value: 90}, 0)
	insertElement(&list, Record{value: 80}, 0)
	insertElement(&list, Record{value: 15}, 0)
	insertElement(&list, Record{value: 1}, 0)

	fmt.Println()
	fmt.Println("Printing the list...")
	print(&list)
	fmt.Println("Size of the list:", size(&list))

	fmt.Println()

	fmt.Println("Deleting element 80 from the list...")
	deleteElement(&list, 80)

	fmt.Println()
	fmt.Println("Printing the list...")
	print(&list)
	fmt.Println("Size of the list:", size(&list))

	fmt.Println()
	fmt.Println("Searching for values in the list:")
	fmt.Println()

	fmt.Println("Searching for the position of number 15:")
	fmt.Printf("Position of number 15: %v \n\n", sequentialSearch(&list, 15))

	fmt.Println("Searching for the position of value 100:")
	fmt.Printf("Position of number 100: %v \n\n", sequentialSearch(&list, 100))
}
