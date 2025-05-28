fun solve() {
  val inputs = readln().split(" ").map { it.toInt() }
  val x = inputs[0]
  val y = inputs[1]
  val d = y / x;
  val left = y - d * x;
  val ans = d.toString().split("").filterNot { it.isBlank() }.map{ it.toInt() }.sum() + left
  println(ans)
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
