class MergeSort {
  void merge(int array[], int start, int middle, int end) {
    int n1 = middle - start + 1;
    int n2 = end - middle;
    int Left[] = new int[n1];
    int Right[] = new int[n2];
    for (int i = 0; i < n1; ++i) Left[i] = array[start + i];
    for (int j = 0; j < n2; ++j) Right[j] = array[middle + 1 + j];
    int i = 0, j = 0;
    int k = start;
    while (i < n1 && j < n2) {
      if (Left[i] <= Right[j]) {
        array[k] = Left[i];
        i++;
      } else {
        array[k] = Right[j];
        j++;
      }
      k++;
    }
    while (i < n1) {
      array[k] = Left[i];
      i++;
      k++;
    }
    while (j < n2) {
      array[k] = Right[j];
      j++;
      k++;
    }
  }

  void sort(int array[], int start, int end) {
    if (start < end) {
      int middle = (start + end) / 2;
      sort(array, start, middle);
      sort(array, middle + 1, end);
      merge(array, start, middle, end);
    }
  }
}
