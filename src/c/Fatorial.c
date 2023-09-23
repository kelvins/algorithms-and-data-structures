#include<stdio.h>
#include<stdlib.h>

/*
*	Examples of a function to return the factorial of a number n
*	Recursive function
*	Jhonata Ribeiro - 2017
*/


int main(){
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    int result = fatorial(num);
    printf("1 => ");
    printf("%d! é : %d\n", num, result);
    return(0);
}

int fatorial(int num){
    if(num <= 1 ){
        return 1;
    }
    printf("%d * ", num);
    return num * fatorial(num - 1);
}
