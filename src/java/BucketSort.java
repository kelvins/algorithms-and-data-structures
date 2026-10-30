public class BucketSort {

  /**
   * @param array array to be sorted; applies Bucket Sort to the array
   */
  public int[] sort(int[] array) {

    final int[] code = hash(array);

    List<Integer>[] buckets = new List[code[1]];
    for (int i = 0; i < code[1]; i++) {
      buckets[i] = new ArrayList<Integer>();
    }

    for (int i : array) {
      buckets[hash(i, code)].add(i);
    }

    for (List bucket : buckets) {
      Collections.sort(bucket);
    }
    int ndx = 0;

    for (int b = 0; b < buckets.length; b++) {
      for (int v : buckets[b]) {
        array[ndx++] = v;
      }
    }
    return array;
  }

  private int[] hash(int[] input) {
    int m = input[0];
    for (int i = 1; i < input.length; i++) {
      if (m < input[i]) {
        m = input[i];
      }
    }
    return new int[] {m, (int) Math.sqrt(input.length)};
  }

  private int hash(int i, int[] code) {
    return (int) ((double) i / code[0] * (code[1] - 1));
  }
}
