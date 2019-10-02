static int v, e; //vertices, aristas
static int MAX=100005; 
static ArrayList<Integer> ady[] = new ArrayList[MAX]; //lista de Adyacencia
static long distance[] = new long[MAX];

//Recibe el nodo inicial
static void bfs(int s){
    Queue<Integer> q = new LinkedList<Integer>();
    q.add(s); 
    distance[s] = 0;
    int actual, i, next;
        
    while( !q.isEmpty() ){
        actual = q.poll();
        for( i = 0; i < ady[actual].size(); i++){
            next = ady[actual].get(i);
            if( distance[next] == -1 ){
                distance[next] = distance[actual] + 1;
                q.add(next);
            }
        }
    }
}
