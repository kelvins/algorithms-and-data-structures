#include <stdio.h>

struct Nodo {
	
	char key;
	Nodo *Par;
	Nodo *Izq;
	Nodo *Der;

};

Nodo *CreaNodo(Nodo valor, int *error);
int InsertarNO(Nodo *r,Nodo item);
void ImprimeArbol(Nodo *r);
void ImprimeArbol2(Nodo *r);
void ImprimeArbol3(Nodo *r);

 int main (){

Nodo *r,valor,*item;
item = new Nodo;
int i=0;
int error,opcion;
char palabra[100];
r=CreaNodo(valor,&error);

if(error==-1){
	printf("No hay memoria\n");
	return -1; 
}

printf("Ingresa palabra deseada:\n");
scanf("%s",palabra);
r->key=palabra[i];
i=i+1;
while(palabra[i] != 0){
	item->key= palabra[i];
	InsertarNO(r,*item);
	i++;
}			

do{
	
		printf("1. Recorrido pre orden\n");
		printf("2. Recorrido In orden\n");
		printf("3. Recorrido Post orden\n");
		printf("4. Salir\n");
		printf("Seleccione un opcion(1-4): \n");
		scanf("%d",&opcion); 


		switch(opcion){

			case 1:ImprimeArbol2(r);
				   printf("\n");
			break;

			case 2:ImprimeArbol(r);
				   printf("\n");
			break;

			case 3:ImprimeArbol3(r);
				   printf("\n");
			break;

			case 4: printf("Hasta luego\n");
			break;

			default: printf("Opcion invalida, vuelva a ingresar un valor\n");

			break;
		}
	}

	while(opcion != 4);


 	return 0;
 }

 Nodo *CreaNodo( Nodo valor, int *error){
	Nodo *NewNodo;
	if((NewNodo= new Nodo)==0){
		*error=-1;
		return NewNodo;
	}
	*NewNodo=valor;
	NewNodo->Par=NewNodo;
	NewNodo->Izq=NewNodo;
	NewNodo->Der=NewNodo;

	return NewNodo;
}

int InsertarNO(Nodo *r,Nodo item){

	Nodo *newnodo;
	int error;
	if(item.key >=r->key){ 
		if(r->Der !=r){   
			error=InsertarNO(r->Der,item);
			return error;
		}
		else{
			newnodo= CreaNodo(item,&error); 
			newnodo->Par=r;          
			r->Der=newnodo;          
			return 1;
		}	
	}
	if(r-> Izq != r){                  
		error =InsertarNO(r->Izq,item);
		return error;
	}
	else{
		newnodo=CreaNodo(item,&error);
		newnodo->Par=r;
		r->Izq=newnodo;
		return 1;
	}
}

void ImprimeArbol(Nodo *r){
	if(r->Izq != r){
		ImprimeArbol(r->Izq);
	}
	printf("%c",r->key);
	if(r->Der != r){
		ImprimeArbol(r->Der);
	}
	return ;
}

void ImprimeArbol2(Nodo *r){

	printf("%c",r->key);
	
	if(r->Izq != r){
		ImprimeArbol2(r->Izq);
	}
	if(r->Der != r){
		ImprimeArbol2(r->Der);
	}
	return;
}

void ImprimeArbol3(Nodo *r){

	if(r->Izq != r){
		ImprimeArbol3(r->Izq);
	}
	if(r->Der != r){
		ImprimeArbol3(r->Der);
	}
	printf("%c",r->key);
	return;
}


void PodaArbol(Nodo *r,int key2, char *dirigirse,int a){

	if(dirigirse[a]== 'R'){
		if(r->key != key2){
			PodaArbol(r->Der,key2,dirigirse,a+1);
			return;
		}
		else{
			r->Par->Der=r->Par;
			return;
		}
	}
	if(r->key != key2){
		PodaArbol(r->Izq,key2,dirigirse,a+1);
		return;
	}
	else{
		r->Par->Izq=r->Par;
		return;
	}
}