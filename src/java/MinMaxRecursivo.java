public class MinMaxRecursivo {

    public static void main(String[] args){
        int[] arr = {9,8,13,33,18,20,88,14,40,77};
        MinMax(arr, arr[0],arr[0],0);
    }

    public static void MinMax(int vect[], int minimo, int maximo, int incide){
        if(vect[incide] < minimo ){
            minimo = vect[incide];
        }
        if(vect[incide] > maximo){
            maximo = vect[incide];
        }
        if(incide < vect.length-1 ){
            MinMax(vect, minimo,maximo, incide+1);
        }
        else {
            System.out.println("Mínimo :" + minimo + "\nMáximo: "+maximo);
        }
    }
}
