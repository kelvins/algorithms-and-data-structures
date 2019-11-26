#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Operaciones(int a[], int n);
void quick_sort(int[],int,int);
int partition(int[],int,int);
void IniciaVector(int a[], int tam);
int Rand();
int Repetido(int a[],int x);
void ImprimeVector(int a[], int tam);
void ImprimeVectorCP(int a[], int tam);

int main()
{
int a[500],n;

n=10;//10, 50, 100, 150, 200 y 500 celdas.
srand(time(NULL));
printf("Con 10 celdas\n");
Operaciones(a,n);
n=50;
printf("Con 50 celdas\n");
Operaciones(a,n);
n=100;
printf("Con 100 celdas\n");
Operaciones(a,n);
n=150;
printf("Con 150 celdas\n");
Operaciones(a,n);
n=200;
printf("Con 200 celdas\n");
Operaciones(a,n);
n=500;
printf("Con 500 celdas\n");
Operaciones(a,n);

return 0;
}

void Operaciones(int a[],int n)
{
IniciaVector(a,n);
printf("Antes de ordenar\n");
ImprimeVector(a,n);
printf("\n");

quick_sort(a,0,n-1);

printf("Despues de ordenar\n");
ImprimeVector(a,n);
}

void IniciaVector(int a[],int tam)
{
srand(time(NULL));
for (int i = 0; i < tam; ++i)
{
a[i]=Rand();
if(Repetido(a,i)==1)
i--;
}
}
int Rand()
{
int X;
X=rand()%100;
return X;
}

int Repetido(int a[],int x)
{
int c=0;
for (int i = 0; i <= x; ++i)
{
if(a[i]==a[x])
c++;
}

if(c>1)
return 1;
return 0;
}

void ImprimeVector(int a[],int tam)
{
for (int i = 0; i < tam; ++i)
{
printf("a[%d] = %d\n",i,a[i] );
}
}

void ImprimeVectorCP(int a[], int tam,int pivote)
{
printf("Vector con el pivote marcado:\n");
for (int i = 0; i <= tam; ++i)
{
if(i==pivote)
printf("a[%d] = %d <-- Pivote\n",i,a[i] );
else
printf("a[%d] = %d\n",i,a[i] );
}
printf("\n");
}

void quick_sort2(int a[],int l,int u)
{
int j;
if(l<u)
{

j=partition(a,l,u);
quick_sort2(a,l,j-1);
quick_sort2(a,j+1,u);
}
}

void quick_sort(int a[],int l,int u)
{
int j;
if(l<u)
{
j=partition(a,l,u);
ImprimeVectorCP(a,u,j);
quick_sort2(a,l,j-1);
quick_sort2(a,j+1,u);
}
}

int partition(int a[],int l,int u)
{
int v,i,j,temp;
v=a[l];
i=l;
j=u+1;

do
{
do
i++;

while(a[i]<v&&i<=u);

do
j--;
while(v<a[j]);

if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}while(i<j);

a[l]=a[j];
a[j]=v;

return(j);
}