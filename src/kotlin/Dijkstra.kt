import java.util.PriorityQueue

// Uses Graph from GraphSearch.kt

fun dijkstra(source: Vertex, target: Vertex): Int {
    val distance: MutableMap<Vertex, Int> = mutableMapOf()

    val queue = PriorityQueue<Vertex> { a, b ->
        val distanceA = distance[a] ?: return@PriorityQueue 0
        val distanceB = distance[b] ?: return@PriorityQueue 0
        distanceA - distanceB
    }
    queue.add(source)
    distance[source] = 0

    while (queue.isNotEmpty()) {
        val currentVertex = queue.poll()
        val currentDistance = distance[currentVertex] ?: Int.MAX_VALUE

        if (currentVertex == target) {
            return currentDistance
        }

        currentVertex.neighbors.forEach { edge ->
            val nextVertexDistance = distance[edge.target] ?: Int.MAX_VALUE
            if (nextVertexDistance > currentDistance + edge.weight) {
                queue.remove(edge.target)
                distance[edge.target] = currentDistance + edge.weight
                queue.add(edge.target)
            }
        }
    }

    return distance[target] ?: -1
}

fun main() {
    val v0 = Vertex("0")
    val v1 = Vertex("1")
    val v2 = Vertex("2")
    val v3 = Vertex("3")
    val v4 = Vertex("4")

    v0.addNeighbor(v1, 6)
    v0.addNeighbor(v2, 10)
    v1.addNeighbor(v3, 2)
    v2.addNeighbor(v3, 1)
    v2.addNeighbor(v4, 3)
    v3.addNeighbor(v4, 8)

    println("Distance 0 -> 4: ${dijkstra(v0, v4)}")
}