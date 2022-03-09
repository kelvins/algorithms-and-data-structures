#include <stdlib.h>

typedef void *tdado;

typedef struct tno {
	tdado dado;
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

TLista appendLista(TLista lst, tdado dado) {
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

tdado primLista(TLista lst) {
	return lst->primeiro->dado;
}

tdado ultLista(TLista lst) {
	return lst->ultimo->dado;
}

TLista insertLista(TLista lst,int i, tdado dado) {
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

tdado infoLista(TLista lst,int i) {
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

tdado removeLista(TLista lst,int i) {
  int tam = lenLista(lst);

  if((i < 0) || (i > tam) || (tam == 0)) return NULL;

  if(tam == 1) { 
     pnoh aux = lst->primeiro;
     lst->primeiro = NULL;
     lst->ultimo = NULL;
     lst->tamanho--;

     tdado d =aux->dado;
     free(aux);

     return d;
  }
  else { 
	 if(i == 0){
	   pnoh aux = lst->primeiro;
	   lst->primeiro = aux->proximo;
	   lst->tamanho--;

	   tdado d =aux->dado;
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

	     tdado d =aux->dado;
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

		 tdado d = aux->dado;
		 free(aux);

		 return d;
	   } 
	 } 
  } 
}

int indexLista(TLista lst, tdado dado){
  int tam = lenLista(lst);
  int i;
  tdado dadolst;

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
