
package cocktailsort

func CocktailSort(slice []int) {

  swapped := true
  begining := 0
  ending := len(slice) - 1

  for begining < ending && swapped {

    for index := begining; index < ending; index++ {
      if slice[index] > slice[index + 1] {
        temp := slice[index]
        slice[index] = slice[index + 1]
        slice[index + 1] = temp
        swapped = true
      }
    }

    ending = ending - 1

    if swapped {
      swapped = false
      for index := ending; index > begining; index-- {
        if slice[index] < slice[index - 1] {
          temp := slice[index]
          slice[index] = slice[index - 1]
          slice[index - 1] = temp
          swapped = true
        }
      }
    }

    begining = begining + 1
  }
}
