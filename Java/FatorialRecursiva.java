public class FatorialRecursiva {
	
	public static void main(String [] args){
		System.out.println("Fatorial de 7 : " + Fatorial(7) );
	}
	
	public static int Fatorial(int x){
		if(x == 1)
			return 1;
		else
			return x * Fatorial(x-1);
	}
}
