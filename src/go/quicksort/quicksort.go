
package quicksort

func QuickSort(slice []int) {
  quick(slice, 0, len(slice)-1)
}

func quick(slice []int, start int, end int) {
  if start < end {
    pivotIndex := split(slice, start, end)
    quick(slice, start, pivotIndex-1)
    quick(slice, pivotIndex+1, end)
  }
}

func split(slice []int, start int, end int) int {
  pivot := slice[end]
  j := start

  for index := start; index < end; index++ {
    if slice[index] < pivot {
      temp := slice[index]
      slice[index] = slice[j]
      slice[j] = temp
      j = j + 1
    }
  }

  if pivot <= slice[j] {
    slice[end] = slice[j]
    slice[j] = pivot
  }
  
  return j
}
