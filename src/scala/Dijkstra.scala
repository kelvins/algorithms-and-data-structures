import scala.annotation.tailrec

trait Path {
  def edges: Seq[Edge]
}
case class ExistingPath(edges: Seq[Edge]) extends Path
object EmptyPath extends Path {
  override def edges: Seq[Edge] = Seq.empty
}

case class Vertex(id: String)
case class Edge(from: Vertex, to: Vertex, distance: Int)
case class Graph(edges: List[Edge]) {

  implicit object EdgesOrdering extends Ordering[Edge] {
    def compare(a: Edge, b: Edge) = a.distance compare b.distance
  }

  @tailrec
  final def dijkstra(start: Vertex, pathComposition: Path = EmptyPath): Path = {
    val startEdges: Seq[Edge] = edges.filter(_.from == start).sorted
    val smallestDistance: Option[Edge] = startEdges
      .filter(e => !pathComposition.edges.map(_.from).contains(e.to))
      .headOption

    smallestDistance match {
      case Some(distance) =>
        dijkstra(
          distance.to,
          ExistingPath(edges = pathComposition.edges.appended(distance))
        )
      case None => pathComposition
    }
  }
}

object Main extends App {

  val startA = Vertex("A")
  val graph: Graph = Graph(
    edges = List(
      Edge(from = Vertex("A"), to = Vertex("B"), distance = 1),
      Edge(from = Vertex("A"), to = Vertex("C"), distance = 4),
      Edge(from = Vertex("B"), to = Vertex("A"), distance = 1),
      Edge(from = Vertex("B"), to = Vertex("C"), distance = 2),
      Edge(from = Vertex("B"), to = Vertex("D"), distance = 5),
      Edge(from = Vertex("C"), to = Vertex("A"), distance = 4),
      Edge(from = Vertex("C"), to = Vertex("B"), distance = 2),
      Edge(from = Vertex("C"), to = Vertex("D"), distance = 1),
      Edge(from = Vertex("D"), to = Vertex("B"), distance = 5),
      Edge(from = Vertex("D"), to = Vertex("C"), distance = 1)
    )
  )

  val result = graph.dijkstra(start = startA)
  println("Calculating path...")
  println(s"Result: ${result.edges}")
}
