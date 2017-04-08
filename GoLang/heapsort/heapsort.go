
package heapsort

func HeapSort(slice []int) []int {

  length := len(slice)
  index := length / 2
  var father int
  var child int
  var temp int

  for {

    if index > 0 {
      index = index - 1
      temp = slice[index]
    } else {
      length = length - 1

      if length == 0 {
        return slice
      }

      temp = slice[length]
      slice[length] = slice[0]
    }

    father = index
    child  = index * 2 + 1

    for child < length {
      if child + 1 < length && slice[child+1] > slice[child] {
        child = child + 1
      }

      if slice[child] > temp {
        slice[father] = slice[child]
        father = child
        child = father * 2 + 1
      } else {
        break
      }
    }

    slice[father] = temp
  }
  return slice
}
