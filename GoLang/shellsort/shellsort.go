package shellsort

func ShellSort(slice []int) {
	size := len(slice)
	gap := 1
	var j int

	for gap < size {
		gap = 3*gap + 1
	}

	for gap > 1 {
		gap = gap / 3
		for index := gap; index < size; index++ {
			value := slice[index]
			j = index - gap

			for j >= 0 && value < slice[j] {
				slice[j+gap] = slice[j]
				j = j - gap
			}
			slice[j+gap] = value
		}
	}
}
