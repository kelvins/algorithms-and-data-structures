package combsort

func CombSort(slice []int) {
	shrinkFactor := 1.247330950103979
	gap := len(slice)
	swapped := true
	i := 0

	for gap > 1 || swapped {
		if gap > 1 {
			gap = int(float64(gap) / shrinkFactor)
		}

		swapped = false
		i = 0

		for gap+i < len(slice) {
			if slice[i]-slice[i+gap] > 0 {
				slice[i], slice[i+gap] = slice[i+gap], slice[i]
				swapped = true
			}
			i++
		}
	}
}
