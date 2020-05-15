
package countingsort

func CountingSort(slice []int) {
  if len(slice) < 1 {
    return
  }

  higher := slice[0]

  for index := 1; index < len(slice); index++ {
    if slice[index] > higher {
      higher = slice[index]
    }
  }

  var temp = make([]int, higher)

  for index := 0; index < len(slice); index++ {
    temp[slice[index] - 1] = temp[slice[index] - 1] + 1
  }

  for index := 1; index < len(temp); index++ {
    temp[index] = temp[index] + temp[index - 1]
  }

  var temp2 = make([]int, len(slice))

  for index := 0; index < len(temp2); index++ {
    temp2[temp[slice[index] - 1] - 1] = slice[index]
    temp[slice[index] - 1] = temp[slice[index] - 1] - 1
  }

  for index := 0; index < len(temp2); index++ {
    slice[index] = temp2[index]
  }
}
