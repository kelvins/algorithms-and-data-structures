#include <stdio.h>

const int THRESHOLD = 32;

int is_odd(int n) { return n & 1; }

int get_fmin(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int get_floor(int n) { return n / 2; }

void print_array(int array[], int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d", array[i]);
    if (i != size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

int get_run_length(int size_of_array) {
  int run_length = size_of_array;
  int remainder = 0;

  while (run_length >= THRESHOLD) {
    if (is_odd(run_length)) {
      remainder = 1;
    }
    run_length = get_floor(run_length / 2);
  }
  return run_length + remainder;
}

void insertion_sort(int array[], int left_index, int right_index) {
  for (int i = left_index + 1; i <= right_index; i++) {
    int temp = array[i];
    int j = i - 1;
    while (j >= left_index && array[j] > temp) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = temp;
  }
}

void merge_runs(int array[], int left_index, int middle_index,
                int right_index) {
  int left_size = middle_index - left_index + 1;
  int right_size = right_index - middle_index;
  int left[left_size];
  int right[right_size];

  for (int i = 0; i < left_size; i++) {
    left[i] = array[left_index + i];
  }
  for (int j = 0; j < right_size; j++) {
    right[j] = array[middle_index + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left_index;

  while (i < left_size && j < right_size) {
    if (left[i] <= right[j]) {
      array[k] = left[i];
      i++;
    } else {
      array[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < left_size) {
    array[k] = left[i];
    i++;
    k++;
  }

  while (j < right_size) {
    array[k] = right[j];
    j++;
    k++;
  }
}

void timsort(int array[], int size) {
  int run_length = get_run_length(size);

  for (int i = 0; i < size; i += run_length) {
    insertion_sort(array, i, get_fmin((i + run_length - 1), (size - 1)));
  }

  for (int size_of_run = run_length; size_of_run < size; size_of_run *= 2) {
    for (int left_index = 0; left_index < size; left_index += 2 * size_of_run) {
      int middle_index = left_index + size_of_run - 1;
      int right_index =
          get_fmin((left_index + 2 * size_of_run - 1), (size - 1));
      merge_runs(array, left_index, middle_index, right_index);
    }
  }
}

int main() {
  int array[] = {5, 2, -2147483648, 1, 4,          5323, -1, 0, 10,
                 9, 8, 7,           6, 2147483647, 4,    3,  2};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Original array:\t");
  print_array(array, size);

  timsort(array, size);

  printf("Sorted array:\t");
  print_array(array, size);
  return 0;
}
