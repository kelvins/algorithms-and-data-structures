fun <T: Comparable<T>> binarySearch(list: List<T>, value: T): Int {
    var start = 0
    var end = list.size - 1
    var middle = end / 2

    while (start != end) {
        when {
            list[middle] < value -> {
                start = middle + 1
                middle = (start + end) / 2
            }
            list[middle] > value -> {
                end = middle
                middle = (start + end) / 2
            }
            list[middle] == value -> {
                return middle
            }
        }
    }

    return -1
}

fun main() {
    print(binarySearch(listOf(1, 5, 10, 12, 18, 22, 87, 90, 112, 129), 12))
}