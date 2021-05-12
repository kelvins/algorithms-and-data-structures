class Main {  

  public static long exponenciacao (long base, long expoente){ //exponenciacao recursiva
    if(expoente==0) return 1;
    return (base * exponenciacao(base, expoente-1));    
  }
  
  public static void main(String args[]) { 
    System.out.println("5 ^ 3 = " + exponenciacao(5,3)); 
  } 
}
