static int v, e; //vertices, aristad
static int MAX=100005; //Cantidad máxima de nodos del grafo
static ArrayList<Integer> ady[] = new ArrayList[MAX]; //Lista de adyacencia
static boolean marked[] = new boolean[MAX]; //Estructura auxiliar para marcar los grafos visitados

//Recibe el nodo inicial s
static void dfs( int s ){
	marked[s] = true;
	int i, next;

	for( i = 0; i < ady[s].size(); i++){
		next = ady[s].get(i);
		if( !marked[next] ){
			dfs(next);
		}
	}
}
