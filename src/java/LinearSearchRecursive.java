public class LinearSearchRecursive {
    public static void main(String[] args) {
        int[] arr = {10,20,50,60,30,60,70,80,22,56,2,7,9,0,44};
        System.out.println(LinearRecursive(arr, 0, 9));
        System.out.println(LinearRecursive(arr, 0, 45));
    }

    public static int LinearRecursive(int[] arr, int i, int key){
        
        if(i<arr.length){
            if(arr[i] == key) return i;
            else return LinearRecursive(arr, i+1, key);
        }

        return -1;
    }
}
