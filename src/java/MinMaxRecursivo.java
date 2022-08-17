public class MinMaxRecursivo {

    public static void main(String[] args){
        int[] arr = {9,8,13,33,18,20,88,14,40,77};
        MinMax(arr, arr[0],arr[0],0);
    }

    public static void MinMax(int vect[], int minimo, int maximo, int indice){
        if(vect[indice] < minimo ){
            minimo = vect[indice];
        }
        if(vect[indice] > maximo){
            maximo = vect[indice];
        }
        if(indice < vect.length-1 ){
            MinMax(vect, minimo,maximo, indice+1);
        }
        else {
            System.out.println("Mínimo :" + minimo + "\nMáximo: "+maximo);
        }
    }
}
