fun solve() {
  val n = readln().toInt();
  if (n == 1) {
    println("1")
  } else if (n == 2) {
    println("2")
  } else if (n == 4) {
    println("1")
  } else if (n == 7) {
    println("1")
  } else {
    println("0")
  }
}

fun main() {
  val t = readln().toInt()
  for (i in 0..<t) {
    solve()
  }
}
