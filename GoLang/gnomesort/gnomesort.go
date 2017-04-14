
package gnomesort

func GnomeSort(slice []int) {
  pivot := 0
  size := len(slice)

  for pivot < size - 1 {
    if slice[pivot] > slice[pivot + 1] {
      temp := slice[pivot]
      slice[pivot] = slice[pivot + 1]
      slice[pivot + 1] = temp
      if pivot > 0 {
        pivot = pivot - 2
      }
    }
    pivot = pivot + 1
  }
}
