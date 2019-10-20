Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos disyuntos en un uno.

static class dsu {
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