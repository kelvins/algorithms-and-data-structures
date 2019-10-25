/*
*   Exemplo Lista Duplamente Encadeada em C
*   Luan Felipe dos S. da Silva
*/


#include <stdio.h>
#include <stdlib.h>

/* Lista encadeada utilizando celula cabeça */

typedef struct cel celula;
struct cel{
    int dado;
    struct cel *prox;
    struct cel *ant;
};

/* O ponteiro 'p' é a cabeça da lista*/

void insereInicio(int x, celula *p) /* Insere no inicio da lista*/
{
   celula *nova, *q;
   nova = malloc (sizeof (celula));
   nova->dado = x;
   nova->prox = p->prox;
   /* verifica se a lista está vazia*/
   if (p->prox != NULL)
   {
      q = nova->prox;
      q->ant = nova;
   }
   p->prox = nova;
   nova->ant = p;
}

void insereUltimo(int x, celula *p) /* Insere no final da lista*/
{
	celula *q;
	celula *nova;
	nova = malloc (sizeof (celula));
	nova->dado = x;
	q = p;
	while (q->prox != NULL)
		q = q->prox;

	q->prox = nova;
	nova->ant = q;
	nova->prox = NULL;
}


void buscaEremove (int y, celula *p)
{
   celula *w, *q;
   w = p;
   q = p->prox;
   while (q != NULL && q->dado != y) {
      w = q;
      q = q->prox;
   }
   if (q != NULL) {
      w->prox = q->prox;
      q->ant = w;
      free (q);
   }
    else{
        printf("\nLista nao contem item\n\n");
        system("pause");
   }
}


void imprime (celula *p)
{
    celula *q;
    for (q = p->prox; q != NULL; q = q->prox)
        printf ("%d  ", q->dado);
}

void Menu ()
{
    printf("  Menu Principal\n");
    printf("1 - Insere inicio\n");
    printf("2 - Insere ultimo\n");
    printf("3 - Retira\n");
    printf("4 - Sair\n");
    printf("\nOpcao: ");
}

void libera (celula *ini)
{
    celula *p;
    p=ini;
    while (p != NULL) {
        celula *q = p->prox; /* guarda referência para o próximo elemento*/
        free(p); /* libera a memória apontada por p */
        p = q; /* faz p apontar para o próximo */
    }
}


int main()
{
    celula  *p;
    int op = 0,item;
    //inicializa lista
    p = malloc (sizeof (celula));
    p->ant = NULL;
    p->prox = NULL;
    //fim_inicializa

    do{
        system("cls");
        printf("\nConteudo da lista: ");
        if (p->prox != NULL){
            imprime(p);
        }
        else{
            printf("Lista VAZIA");
        }
        printf("\n\n");
        Menu();
        scanf("%d",&op);
        switch (op){
            case 1:
                printf("Insere no inicio da lista: ");
                scanf("%d",&item);
                insereInicio(item,p);
                break;
            case 2:
               printf("Insere na ultima posicao da lista: ");
               scanf("%d",&item);
               insereUltimo(item,p);
               break;
            case 3:
                if (p->prox != NULL){
                    printf("Retirar um elemento: ");
                    scanf("%d",&item);
                    buscaEremove(item,p);
                }
                else{
                    printf("\nLista VAZIA\n\n");
                    system("pause");
                }
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
                system("pause");
                break;
        }

    }while(op!=4);
    libera(p);
    return 0;
}
