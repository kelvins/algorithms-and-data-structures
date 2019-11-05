#include <stdio.h>
#define MAX 5

typedef struct Nodo
{
	int val;		//Valor del nodo
	int grado;		//Valor del grado del Arbol
	int orden;		//Valor del orden
	int elem;		//Cantidad de elementos
	Nodo *ant;		//Apuntador a un nodo anterior
	Nodo *sig;		//Apuntador a un nodo siguiente
	Nodo *pder;		//Apuntador a la pagina derecha
	Nodo *pizq;		//Apuntador a la pagina izquierda
	Nodo *aizq;	//Apuntador al arreglo izquierdo
	Nodo *ader;	//Apuntador al arreglo derecho
};

/*
	Faltantes
		*Reestructuracion del Arbol
		*Eliminacion
		*Borrar este comentario XD 
*/

void CreaNodo(Nodo **R,int val);		//Creacion del nodo 
void Inserta(Nodo **P,int val);			//Insercion paso 1
void InsertaArr(Nodo **P, int val);		//Insercion paso 2
void CreaNodo(Nodo **R,int val);		//Creacion del nodo para la lista
void Recorre(Nodo *P);					//Recorrido de los arreglos que se han tratado como lista
void BusquedaArr(Nodo *T,int val);		//Busqueda en arreglos
void BusquedaPag(Nodo *Pag,int val);	//Busqueda en paginas
void ImprimeArbolB(Nodo *P);			//Impresion del arbol B
void LiberaMemoriaPag(Nodo **P);
void LiberaMemoriaArr(Nodo **P);

int main ()

{	
	Nodo *P=NULL;
	CreaNodo(&P,20);
	Inserta(&P,10);
	Inserta(&P,11);
	Inserta(&P,12);
	Inserta(&P,13);
    Inserta(&P,2);
	Inserta(&P,22);
	Inserta(&P,21);
    printf("\nBUSCARE EL NUMERO 10 -->");
    BusquedaPag(P,10);
	ImprimeArbolB(P);
    printf("\nMemoria liberada");
	LiberaMemoriaPag(&P);
	return 0;
}

void CreaNodo(Nodo **R,int val)		//Creacion del nodo 
{
	Nodo *Newnodo=*R;
	Newnodo= new Nodo;
	Newnodo->val=val;
	Newnodo->ant=NULL;
	Newnodo->sig=NULL;
	Newnodo->pizq=NULL;
	Newnodo->pder=NULL;
	Newnodo->aizq=NULL;
	Newnodo->ader=NULL;
	*R=Newnodo;
}

void CreaNodoAr(Nodo **R,int val)		//Creacion del nodo para la lista
{
	Nodo *Newnodo=*R;
	Newnodo= new Nodo;
	Newnodo->val=val;
	Newnodo->ant=NULL;
	Newnodo->sig=NULL;
	*R=Newnodo;
}

void Inserta(Nodo **P,int val)	//Insercion del valor
{
	Nodo *pag=*P,*Ap=pag;

	while(val<Ap->val && Ap->sig!=NULL)	//Encontrar el lugar ideal para el valor
	{
		Ap=Ap->sig;
	}
	if(val==Ap->val)		//Si ya existe el valor
	{
		printf("Ya existe el valor %d\n",val);
	}	
	if(val<Ap->val)			//Si es menor
	{
		if(Ap->pizq!=NULL)	//Si su hijo izquierdo es una pagina 
		{
			Inserta(&Ap->pizq,val);
			return;
		}
		else 				//Si no significa que su hijo izquierdo es un arreglo
		{
			InsertaArr(&Ap->aizq,val);
		}
	}
	if(val>Ap->val)			//Si es mayor se hace lo mismo que con el menor pero con los lados derechos
	{
		if(Ap->pder!=NULL)
		{
			Inserta(&Ap->pder,val);
		}
		else
		{
			InsertaArr(&Ap->ader,val);
			return;
		}
	}
	*P=pag;
}

void InsertaArr(Nodo **P, int val)	//Insercion como en listas
{
	Nodo *T=*P,*R=*P,*Q;
	int cont=1;
	CreaNodo(&Q,val);	//Se crea el nodo a insertar
	if(*P==NULL)
	{
		Q->elem=1;
		*P=Q;
		return;
	}
	if(T->val>Q->val)	//Insercion como primer elemento
	{
		Q->sig=T;
		Q->elem=2;
		Q->ant=T->ant;
		T->ant=Q;
		*P=Q;
		return;
	}
	else
	{
		while(T->sig!=NULL && Q->val>T->val && T->val!=Q->val)	//Busqueda del lugar ideal para el nodo
		{
			T=T->sig;
			cont++;
		}
	
		if(T->val==Q->val)
		{
			printf("Ya existe el valor %d\n",Q->val);
			return;
		}
		R->elem=cont+1;
		*P=R;
		if(T->sig==NULL && T->val<Q->val)
		{
			
			T->sig=Q;
			Q->ant=T;
			Q->sig=NULL;
		}
		else
		{
			R->sig=Q;
			Q->ant=R;
			T->ant=Q;
			Q->sig=T;
		}
	}
}


void ImprimeArbolB(Nodo *Pag)	//Impresion del arbol (In orden)
{
	Nodo *Ap=Pag;

	if(Pag->pizq!=NULL)			//Se imprimen todas las paginas izquierdas
	{
		ImprimeArbolB(Pag->pizq);
	}
	if(Pag->aizq!=NULL)			//Se imprimen todas los arreglos izquierdos
	{
		Recorre(Pag->aizq);
	}
	printf("%d ", Pag->val);	//Se imprime el valor del nodo
	if(Pag->pder!=NULL)			//Se imprimen todas las paginas derechas
	{
		ImprimeArbolB(Pag->pder);
	}
	if(Pag->ader!=NULL)			//Se imprimen todos los arreglos derechos
	{
		Recorre(Pag->ader);
	}
	while(Ap->sig!=NULL)		//Ciclo para imprimir todos los nodos de una pagina
	{
		if(Ap->pder!=NULL)		//Se imprimen todas las paginas derechas
		{
			ImprimeArbolB(Ap->pder);
		}
		if(Ap->ader!=NULL)		//Se imprimen todos los arreglos derechos
		{
			Recorre(Ap->ader);
		}
		Ap=Ap->sig;
	}
}

void Recorre(Nodo *P)		//Impresion como en listas
{
	Nodo *T=P;
	if(P==NULL)	//Si la lista esta vacia
	{
		printf("Lista Vacia\n");
	}
	else
	{
		while(T->sig!=NULL)
		{
			printf("%d ",T->val );
			T=T->sig;
		}
		printf("%d ",T->val );
	}
}

void BusquedaPag(Nodo *Pag,int val)	//Busqueda por paginas
{
	Nodo *Ap=Pag;
	if(Pag->val==val)	//Si se encuentra el valor en el nodo de la pagina actual se encontro
	{
		printf("Si se encuentra el valor %d\n",val );
	}
	else
	{
		while(val>Ap->val && Ap->sig!=NULL && val!=Ap->val)	//Mientras el valor sea mayor, no se encuentre y la pagina tenga nodos
		{
			Ap=Ap->sig;
		}
		if(val==Ap->val)	//Si se encontro el valor
		{
			printf("Si se encuentra el valor %d\n",val );
			return;
		}
		if (Ap->val<val)	//Si el valor es Mayor al del nodo actual
		{
			if(Ap->pder!=NULL)	//Si tiene una pagina como hijo derecho
			{
				BusquedaPag(Ap->pder,val);
			}
			if(Ap->ader!=NULL)	//Si tiene un arreglo como hijo derecho
			{
				BusquedaArr(Ap->ader,val);
			}
			
		}
		if(Ap->val>val)		//Si el valor es Menor al nodo actual
		{
			if (Ap->pizq!=NULL)	//Si tiene una pagina como hijo izquierdo
			{
				BusquedaPag(Ap->pizq,val);
			}
			if(Ap->aizq!=NULL)
			{
				BusquedaArr(Ap->aizq,val);
			}
			return;
		}
		printf("No se encuentra el valor %d\n",val );
	}
	
}

void BusquedaArr(Nodo *T,int val)	//Funcion que busca en el arreglo terminal, de la misma manera que se hace en listas 
{
	if(T==NULL)
	{
		printf("No se encuentra el valor %d\n", val);
		return;
	}
	else
	{
		while(T->sig!=NULL && T->val!=val)
		{
			T=T->sig;
		}
		if(T->val==val)
		{
			printf("Si se encuentra el valor %d\n",val );
			
		}
		else
		{
			printf("No se encuentra el valor %d\n",val );
		}
		return ;
	}	
}

void LiberaMemoriaPag(Nodo **P)	//Liberacion de memoria
{
	Nodo *Ap=*P,*Y;
	while(Ap->sig!=NULL)
	{
		if(Ap->pizq!=NULL)
		{
			LiberaMemoriaPag(&Ap->pizq);
		}
		if(Ap->aizq!=NULL)
		{
			LiberaMemoriaArr(&Ap->aizq);
		}
		Y=Ap;
		Ap=Ap->sig;
		delete Y;
	}
	if(Ap->pder!=NULL)
	{
		LiberaMemoriaPag(&Ap->pder);
	}
	if(Ap->ader!=NULL)
	{
		LiberaMemoriaArr(&Ap->ader);
	}
	delete Ap;
	Ap=NULL;
	*P=Ap;
}

void LiberaMemoriaArr(Nodo **P) 	//Liberacion de memoria
{
	Nodo *T=*P,*Y;
	if(T==NULL)
	{
		return;
	}
	else
	{
		if(T->sig==NULL)
		{
			delete T;
			T=NULL;
			*P=T;
		}
		else{
			
			while(T->sig!=NULL )
			{
				Y=T;
				T=T->sig;
				delete Y;
			}
			delete T;
			T=NULL;
			*P=T;
			return;
		}
	}
}