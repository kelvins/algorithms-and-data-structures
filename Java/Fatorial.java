
public class Fatorial {
	
	public static void main(String [] args){
		System.out.println("Fatorial de 7 : " + Fatorial(7) );
	}
	
	public static int Fatorial(int x){
		int total = 1;
		for (int i = 2; i < x+1; i++) {
			total = total * i;
		}
		return total;
	}
	
}
