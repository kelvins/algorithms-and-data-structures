#include <stdlib.h>
#include <stdio.h>

typedef struct tno {
	/*Caso queira usar isso para qualquer um use TAD
	E com o TAD defina: typedef void *tdado;
	E em todo local do código relacionado ao dado
	troque int por tdado.
	*/
	int dado;
	struct tno *anterior; 
	struct tno *proximo;
} tipoNo;

typedef tipoNo *pnoh;

typedef struct {
	int tamanho;
	pnoh primeiro;
	pnoh ultimo;
} tcabec;

typedef tcabec *TLista;


TLista criaLista() {
	TLista c = (tcabec *)malloc(sizeof(tcabec));

	c->tamanho = 0;
	c->primeiro = NULL;
	c->ultimo = NULL;

	return c;
}

TLista appendLista(TLista lst, int dado) {
	pnoh novono = (tipoNo *)malloc(sizeof(tipoNo));

	novono->dado = dado;
	novono->anterior = lst->ultimo; 
	novono->proximo = NULL;

	if(lst->tamanho == 0){
		lst->primeiro = novono;
		lst->ultimo = novono;
	}
	else {
		lst->ultimo->proximo = novono;
		lst->ultimo = novono;
	}

	lst->tamanho++;

	return lst;
}

int lenLista(TLista lst) {
	return lst->tamanho;
}

int primLista(TLista lst) {
	return lst->primeiro->dado;
}

int ultLista(TLista lst) {
	return lst->ultimo->dado;
}

TLista insertLista(TLista lst,int i, int dado) {
  int tam = lenLista(lst);

  if((i < 0) || (i > tam)) return NULL;

  if(lenLista(lst) == 0)
    appendLista(lst,dado);
  else
    if(i==tam)
      appendLista(lst,dado);
    else {
        if(i == 0) {
          pnoh novono = (tipoNo *)malloc(sizeof(tipoNo));
          novono->dado = dado;

          novono->proximo = lst->primeiro;
          lst->primeiro = novono;
        }
        else {
          pnoh novono = (tipoNo *)malloc(sizeof(tipoNo));
          novono->dado = dado;

          pnoh aux = lst->primeiro;
          int pos = 0;

          while(pos != (i - 1)){
            aux = aux->proximo;
            pos++;
          }
          novono->proximo = aux->proximo;
          aux->proximo = novono;
        }

        lst->tamanho++;
    }

  return lst;
}

int infoLista(TLista lst,int i) {
  int tam = lenLista(lst);

  if((tam == 0) || (i < 0) || (i > tam))
    return NULL;

  if(i == 0) return lst->primeiro->dado;

  else if(i == tam - 1) return lst->ultimo->dado;
  else {
    pnoh aux = lst->primeiro;
    int pos = 0;

    while(pos != i){
      aux = aux->proximo;
      pos++;
    }

    return aux->dado;
  }
}

int removeLista(TLista lst,int i) {
  int tam = lenLista(lst);

  if((i < 0) || (i > tam) || (tam == 0)) return NULL;

  if(tam == 1) { 
     pnoh aux = lst->primeiro;
     lst->primeiro = NULL;
     lst->ultimo = NULL;
     lst->tamanho--;

     int d =aux->dado;
     free(aux);

     return d;
  }
  else { 
	 if(i == 0){
	   pnoh aux = lst->primeiro;
	   lst->primeiro = aux->proximo;
	   lst->tamanho--;

	   int d =aux->dado;
	   free(aux);

	   return d;
	 }
	 else {
	   if(i == tam - 1) { 
		 pnoh aux = lst->ultimo;

		 pnoh penultimo = lst->primeiro;
		 int pos = 0;

		 while(pos != i-1){
			 penultimo = penultimo->proximo;
			 pos++;
		 }

		 penultimo->proximo = NULL;
		 lst->ultimo = penultimo;

		 lst->tamanho--;

	     int d =aux->dado;
	     free(aux);

	     return d;
	   } 
	   else {
		 pnoh anterior = lst->primeiro;
		 int pos = 0;

		 while(pos != i-1){
			 anterior = anterior->proximo;
			 pos++;
		 }

		 pnoh aux = anterior->proximo;
		 anterior->proximo = aux->proximo;
		 lst->tamanho--;

		 int d = aux->dado;
		 free(aux);

		 return d;
	   } 
	 } 
  } 
}

int indexLista(TLista lst, int dado){
  int tam = lenLista(lst);
  int i;
  int dadolst;

  if(tam == 0) return -1;

  i = 0;
  dadolst = infoLista(lst,i);
  while((i < tam) && (dado != dadolst)){
	  i++;
  	  dadolst = infoLista(lst,i);
  }

  if(i < tam) return i;
  else return -1;
}

TLista clearLista(TLista lst){
  int tam = lenLista(lst);

  if(tam == 0) return lst;

  while(lenLista(lst) > 0)
	  removeLista(lst,0);

  return lst;
}

TLista clonaLista(TLista lst){
  TLista clone = criaLista();
  int tam = lenLista(lst);

  if(tam == 0) return clone;

  for(int i=0;i < tam; i++)
	 appendLista(clone,infoLista(lst,i));

  return clone;
}

int main(){
  TLista lista = criaLista();
  appendLista(lista, 3);
  appendLista(lista, 5);
  appendLista(lista, 7);
  printf("Lista criada e adicionado 3 numeros\n");
  int tamanho = lenLista(lista);
  int primeiro = primLista(lista);
  int ultimo = ultLista(lista);
  int valor = infoLista(lista, 1);
  printf("Tamanho da lista: %d\nPrimeiro da Lista: %d\nUltimo da Lista: %d\nSegundo valor: %d\n", tamanho, primeiro, ultimo, valor);
  insertLista(lista, 2, 6);
  valor = infoLista(lista, 2);
  printf("Adicionando 6 na posição 2: %d\n", valor);
  removeLista(lista, 1);
  tamanho = lenLista(lista);
  printf("Novo tamanho após adicionar e remover: %d\n", tamanho);
  int index = indexLista(lista, 3);
  printf("Index do elemento com valor 3 na lista: %d\n", index);
  TLista cloneLista = clonaLista(lista);
  printf("Lista Duplicada\n");
  clearLista(lista);

  printf("Lista Apagada");

  return 0;
}
