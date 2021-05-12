class Main {  

  public static long exponenciacao(int base, int expoente){

	int i;
	int result = base;
	
	for(i=0; i<expoente-1; i++)
		result *= base;
    
	return result;
}

  
  public static void main(String args[]) { 
    System.out.println("5 ^ 3 = " + exponenciacao(5,3)); 
  } 
}
