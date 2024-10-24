def isPalindrome(content: String): Boolean = {
  val sanitizedContent: String = content.replaceAll("\\W", "").toLowerCase
  sanitizedContent == sanitizedContent.reverse
}

object Main extends App {
  val data: Seq[String] = Seq(
    "",
    "a",
    "abba",
    "No lemon, no melon",
    "Was it a palindrome?"
  )
  data.foreach(x => println(s"'$x' is a palindrome? ${isPalindrome(x)}"))
}
