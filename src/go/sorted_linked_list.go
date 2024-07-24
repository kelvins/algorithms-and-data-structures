/*
* Lists - Ordered linear list
*
* Implementation of a sequential list whose elements are ordered
*
* Go PlayGround link: https://play.golang.org/p/J6Jbi2_FWJk
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

// Performs binary search on the list
func binarySearch(list *List, value int) int {
	left := 0
	right := list.numberOfElements - 1

	for left <= right {
		middle := ((left + right) / 2)
		if list.recordArray[middle].value == value {
			return middle
		}

		if list.recordArray[middle].value < value {
			left = middle + 1
		} else {
			right = middle - 1
		}
	}

	return -1
}

// Inserts elements into the list in ascending order, ensuring that the list is always sorted
func insertRecordInOrder(list *List, record Record) bool {
	if list.numberOfElements == maxSize {
		return false
	}

	position := list.numberOfElements

	for position > 0 && list.recordArray[position-1].value > record.value {
		list.recordArray[position] = list.recordArray[position-1]
		position--
	}

	list.recordArray[position] = record
	list.numberOfElements++

	return true
}

// Deletes an element from the list
func deleteElement(list *List, value int) bool {
	position := binarySearch(list, value)

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
	insertRecordInOrder(&list, Record{value: 20})
	insertRecordInOrder(&list, Record{value: 10})
	insertRecordInOrder(&list, Record{value: 70})
	insertRecordInOrder(&list, Record{value: 30})
	insertRecordInOrder(&list, Record{value: 60})
	insertRecordInOrder(&list, Record{value: 90})
	insertRecordInOrder(&list, Record{value: 80})
	insertRecordInOrder(&list, Record{value: 15})
	insertRecordInOrder(&list, Record{value: 1})

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
	fmt.Println("Searching values in the list:")
	fmt.Println()

	fmt.Println("Searching position of number 15:")
	fmt.Printf("Position of number 15: %v \n\n", binarySearch(&list, 15))

	fmt.Println("Searching position of value 100:")
	fmt.Printf("Position of number 100: %v \n\n", binarySearch(&list, 100))
}
