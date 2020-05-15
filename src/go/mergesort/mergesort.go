package mergesort

func MergeSort(slice []int) {
	if len(slice) > 1 {
		half := len(slice) / 2

		var sliceLeftSide []int
		var sliceRightSide []int

		for index := 0; index < half; index++ {
			sliceLeftSide = append(sliceLeftSide, slice[index])
		}

		for index := half; index < len(slice); index++ {
			sliceRightSide = append(sliceRightSide, slice[index])
		}

		MergeSort(sliceLeftSide)
		MergeSort(sliceRightSide)

		i := 0
		j := 0
		k := 0

		for i < len(sliceLeftSide) && j < len(sliceRightSide) {
			if sliceLeftSide[i] < sliceRightSide[j] {
				slice[k] = sliceLeftSide[i]
				i = i + 1
			} else {
				slice[k] = sliceRightSide[j]
				j = j + 1
			}
			k = k + 1
		}

		for i < len(sliceLeftSide) {
			slice[k] = sliceLeftSide[i]
			i = i + 1
			k = k + 1
		}

		for j < len(sliceRightSide) {
			slice[k] = sliceRightSide[j]
			j = j + 1
			k = k + 1
		}
	}
}
