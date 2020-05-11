
public class teste {
	public static void main(String[] args) {
		int[] arrayteste = {10,8,6,4,2,0,1,3,5,7,9};
		MergeSort ordem = new MergeSort(); 
	    ordem.sort(arrayteste, 0, arrayteste.length-1); 
		for (int i = 0; i < arrayteste.length; i++) {
			System.out.print(arrayteste[i] + " ");
		}
	}
}
