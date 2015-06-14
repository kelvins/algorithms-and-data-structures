
public class Fibonacci {

	public static void main(String [] args){
		System.out.println("Fib(16) : " + Fibonacci(16) );
		System.out.println("Fib(16) : " + FibonacciRecursivo(16) );
	}
	
	public static int FibonacciRecursivo(int x){
		if(x <= 1)
			return 1;
		else
			return Fibonacci(x-1) + Fibonacci(x-2);
	}
	
	public static int Fibonacci(int x){
		if(x <= 1){
			return 1;
		}else{
			int n = 1, prox = 1;
			for (int i = 0; i < x-1; i++) {
				int temp = prox;
				prox = prox + n;
				n = temp;
			}
			return n;
		}
	}
}
