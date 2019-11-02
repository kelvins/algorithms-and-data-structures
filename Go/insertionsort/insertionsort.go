package insertionsort

func InsertionSort(slice []int) {
	for index1 := 1; index1 < len(slice); index1++ {
		currentValue := slice[index1]
		index2 := index1 - 1

		for index2 >= 0 && currentValue < slice[index2] {
			slice[index2+1] = slice[index2]
			index2 = index2 - 1
		}

		slice[index2+1] = currentValue
	}
}
