package buscabinaria

func binarySearch(seq []int, element, start, end int) int {
	index := (start + end) / 2

	if index < len(seq) && seq[index] == element {
		return index
	}

	if start != end {
		if seq[index] < element {
			return binarySearch(seq, element, index+1, end)
		}

		return binarySearch(seq, element, start, index-1)
	}

	return -1
}

func BinarySearch(sequence []int, number int) int {
	return binarySearch(sequence, number, 0, len(sequence))
}
