public class Palindromo {
    public static void main(String[] args){
        String palavra, palavraInvertida="";
        palavra = "A grama é amarga";

        for(int i=palavra.length()-1; i>=0; i--){
            palavraInvertida += palavra.toLowerCase().charAt(i);
        }

        if(palavra.replace(" ","").toLowerCase().equals(palavraInvertida.replace(" ","")))
            System.out.println("palavra é um palindromo!");
        else
            System.out.println("palavra não é um palindromo!");
    }
}


