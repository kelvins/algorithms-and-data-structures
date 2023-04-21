package gnomesort

func GnomeSort(slice []int) {
	pivot := 0
	size := len(slice)

	for pivot < size-1 {
		if slice[pivot] > slice[pivot+1] {
			slice[pivot], slice[pivot+1] = slice[pivot+1], slice[pivot]
			if pivot > 0 {
				pivot -= 2
			}
		}
		pivot++
	}
}
