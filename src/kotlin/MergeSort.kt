fun mergeSort(arr: IntArray): IntArray {
    if (arr.size <= 1) {
        return arr
    }

    val middle = arr.size / 2
    val left = arr.copyOfRange(0, middle)
    val right = arr.copyOfRange(middle, arr.size)

    return merge(mergeSort(left), mergeSort(right))
}

fun merge(
    left: IntArray,
    right: IntArray,
): IntArray {
    var result = IntArray(left.size + right.size)
    var leftIndex = 0
    var rightIndex = 0
    var resultIndex = 0

    while (leftIndex < left.size && rightIndex < right.size) {
        if (left[leftIndex] < right[rightIndex]) {
            result[resultIndex] = left[leftIndex]
            leftIndex++
        } else {
            result[resultIndex] = right[rightIndex]
            rightIndex++
        }
        resultIndex++
    }

    while (leftIndex < left.size) {
        result[resultIndex] = left[leftIndex]
        leftIndex++
        resultIndex++
    }

    while (rightIndex < right.size) {
        result[resultIndex] = right[rightIndex]
        rightIndex++
        resultIndex++
    }

    return result
}

fun main() {
    val arr = intArrayOf(12, 11, 13, 5, 6, 7)
    val sortedArray = mergeSort(arr)
    println("Sorted array: ${sortedArray.joinToString(", ")}")
}
