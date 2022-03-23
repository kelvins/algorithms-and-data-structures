#include <stdio.h>

#define TRUE 1
#define FALSE 0

int binarySearch(int array[], int value, int len)
{
  int mid = len / 2;
  int newArray[mid];
  int result = FALSE;

  if (value > array[mid] && len >= 1)
  {
    for (int i = 0; i < mid; i++)
      newArray[i] = array[(mid + 1) + i];

    result = binarySearch(newArray, value, mid);
  }
  else if (value < array[mid] && len >= 1)
  {
    for (int i = 0; i < mid; i++)
      newArray[i] = array[i];
    
    result = binarySearch(newArray, value, mid);
  }
  else if (value == array[mid])
    return TRUE;
  else
    return FALSE;
 
  return result;
}

int main()
{
  int array[30];

  for (int i = 0; i < 30; i++)
    array[i] = i * 2;

  int result = binarySearch(array, 17, 30);

  printf("%d\n", result);
}
