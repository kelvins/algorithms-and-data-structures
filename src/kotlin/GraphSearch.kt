class Edge(val target: Vertex, val weight: Int = 1)

class Vertex(val label: String, var neighbors: MutableList<Edge> = mutableListOf()) {
    fun addNeighbor(other: Vertex, weight: Int = 1) {
        other.neighbors.add(Edge(this, weight))
        this.neighbors.add(Edge(other, weight))
    }

    override fun hashCode(): Int {
        return label.hashCode()
    }

    override fun equals(other: Any?): Boolean {
        if (other !is Vertex) {
            return false
        }
        return label == other.label
    }
}

// Returns the distance found, or -1 when not found
fun dfs(source: Vertex, target: Vertex): Int {
    val visited: MutableMap<Vertex, Boolean> = mutableMapOf()

    return _dfs(source, target, visited)
}

internal fun _dfs(source: Vertex, target: Vertex, visited: MutableMap<Vertex, Boolean>): Int {
    visited[source] = true
    if (source == target) return 0
    source.neighbors.forEach { edge ->
        if (visited[edge.target] == true) {
            return@forEach
        }
        _dfs(edge.target, target, visited).let {
            if (it != -1) {
                return it + edge.weight
            }
        }
    }
    return -1
}

// Returns the distance found, or -1 when not found
fun bfs(source: Vertex, target: Vertex): Int {
    val distance: MutableMap<Vertex, Int> = mutableMapOf()

    val queue = mutableListOf(source)
    distance[source] = 0

    while (queue.isNotEmpty()) {
        val currentVertex = queue.removeFirst()
        if (currentVertex == target) {
            return distance[currentVertex]!!
        }
        currentVertex.neighbors.forEach { edge ->
            if (distance[edge.target] == null) {
                distance[edge.target] = distance[currentVertex]!! + edge.weight
                queue.add(edge.target)
            }
        }
    }

    return -1
}

fun main() {
    val A = Vertex("A")
    val B = Vertex("B")
    val C = Vertex("C")
    val D = Vertex("D")
    val E = Vertex("E")
    val F = Vertex("F")


    A.addNeighbor(B)
    A.addNeighbor(C)
    B.addNeighbor(D)
    C.addNeighbor(D)
    B.addNeighbor(E)
    D.addNeighbor(E)
    E.addNeighbor(F)
    D.addNeighbor(F)

    println("DFS A -> F: ${dfs(A, F)}")

    println("BFS A -> F: ${bfs(A, F)}")
}