public class BuscaSequencial {

    public static void main(String[] args) {
        Object[] vector = {2, 34, 42, 23};
        System.out.println(sequentialSearch(34, vector)); // out: 1
    }

    public static int sequentialSearch(Object key, Object[] vector) {
        for (int i = 0; i < vector.length; i++) {
            if (vector[i].equals(key)) {
                return i;
            }
        }
        return -1;
    }
}
