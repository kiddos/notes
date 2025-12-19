fun solve() {
  val inputs = readln().split(' ').map{ it.toLong() }
  val n = inputs[0]
  val a = readln().split(' ').map{ it.toLong() }
  val b = a.sorted()
  var ans = 0L
  for (i in 0..<n) {
    val buy = n - i
    val m = b[i.toInt()]
    ans = Math.max(ans, m * buy)
  }
  println(ans)
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
