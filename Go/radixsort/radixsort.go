
package radixsort

func RadixSort(slice []int) {

  if len(slice) == 0 {
    return
  }

  length := len(slice)
  higher := slice[0]
  exp := 1
  var temp []int

  for index := 0; index < length; index++ {
    temp = append(temp, 0)
    if slice[index] > higher {
      higher = slice[index]
    }
  }

  for higher/exp > 0 {
    var bucket [10]int

    for index := 0; index < length; index++ {
      bucket[(slice[index]/exp) % 10] = bucket[(slice[index]/exp) % 10] + 1
    }

    for index := 1; index < 10; index++ {
      bucket[index] = bucket[index] + bucket[index-1]
    }

    for index := length-1; index >= 0; index-- {
      bucket[(slice[index] / exp) % 10] = bucket[(slice[index] / exp) % 10] - 1
      temp[bucket[(slice[index] / exp) % 10]] = slice[index]
    }

    for index := 0; index < length; index++ {
      slice[index] = temp[index]
    }

    exp = exp * 10
  }
}
