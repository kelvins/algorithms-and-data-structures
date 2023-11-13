#include<stdio.h>



int exponenciacao(int base, int expoente){

	int i;
	int result = base;
	
	for(i=0; i<expoente-1; i++)
		result *= base;

	return result;

}



int main(){
	
	printf("%d\n", exponenciacao(5, 3));

	return 0;
}
