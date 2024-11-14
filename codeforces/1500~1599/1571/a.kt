fun solve() {
  val s = readln()
  var greater = 0
  var less = 0
  for (ch in s) {
    if (ch == '>') {
      greater++
    } else if (ch == '<') {
      less++
    }
  }

  if (greater > 0 && less > 0) {
    println("?")
  } else if (greater > 0) {
    println(">")
  } else if (less > 0) {
    println("<")
  } else {
    println("=")
  }
}

fun main() {
  val t = readln().toInt()
  for (i in 1..t) {
    solve()
  }
}
