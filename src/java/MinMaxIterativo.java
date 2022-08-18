public class MinMaxIterativo {
    public static void main(String[] args){
        int arr[] = {1, 5, -20, 6, 15};
        int min = arr[0];
        int max = arr[0];

        for (int i:arr) {
            if(i < min) min = i;
            else if(i > max) max = i;
        }
        System.out.println("Max: " + max + "\nMin: " + min);
    }
}
