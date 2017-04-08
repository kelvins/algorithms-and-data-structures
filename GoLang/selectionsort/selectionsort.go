package selectionsort

func SelectionSort(slice []int) {
	for index1 := 0; index1 < len(slice)-1; index1++ {
		indexMin := index1

		for index2 := index1 + 1; index2 < len(slice); index2++ {
			if slice[index2] < slice[indexMin] {
				indexMin = index2
			}
		}

		if index1 != indexMin {
			swap := slice[index1]
			slice[index1] = slice[indexMin]
			slice[indexMin] = swap
		}
	}
}
