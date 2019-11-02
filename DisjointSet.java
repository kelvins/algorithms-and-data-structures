Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos disyuntos en un uno.

import java.util.*;
import java.lang.*;
import java.io.*;

// Estructura de datos para modelar una colección de conjuntos disyuntos.
// Permite determinar de manera eficiente a que conjunto pertenece un elemento,
// si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos disyuntos en un uno.

class dsu {
    int[] par, sz;
    int size; //Cantidad de conjuntos

    dsu(int n) {
        size = n;
        par = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    //Busca el nodo representativo del conjunto de u
    int find(int u) {
        return par[u] == u ? u : (par[u] = find(par[u]));
    }
    //Une los conjuntos de u y v
    void unite(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return;
        if (sz[u] > sz[v]){
            int aux = u;
            u = v;
            v = aux;
        }
        par[u] = v;
        sz[v] += sz[u];
        size--;
    }
    //Retorna la cantidad de elementos del conjunto de u
    int count(int u) {
        return sz[find(u)];
    }
};


class ejemplo{
    static int n = 10; //cantidad de nodos
    public static void main(String args[]){
        dsu ex_dsu = new dsu(n);
        ex_dsu.unite(1,2);	//une el nodo 1 con el nodo 2
        ex_dsu.unite(3,4);	//une el nodo 3 con el nodo 4
        ex_dsu.unite(2,3);	//une el conjunto del nodo 2 con el conjunto del nodo 3
        ex_dsu.unite(8,5);	//une el nodo 8 con el nodo 5
        ex_dsu.unite(9,8);	//une el nodo 9 con el conjunto del nodo 8
        ex_dsu.unite(6,5);	//une el nodo 6 con el conjunto del nodo 5
		/* Los conjuntos quedarian conformados así
		[4,3,2,1] y [5,8,9,6]
		como el nodo 7 y el nodo 0 no se unieron son conjuntos unitarios
		*/
        System.out.println("El nodo representativo de 5 es: " + ex_dsu.find(5));
        System.out.println("El nodo representativo de 1 es: " + ex_dsu.find(1));
        System.out.println("El nodo representativo de 7 es: " + ex_dsu.find(7));
        System.out.println("La cantidad de nodos del conjunto donde se encuentra el nodo 5 es: " + ex_dsu.count(5));
        System.out.println("La cantidad de nodos del conjunto donde se encuentra el nodo 1 es: " + ex_dsu.count(1));
        System.out.println("La cantidad de nodos del conjunto donde se encuentra el nodo 7 es: " + ex_dsu.count(7));
        

	}    
}
