fun solve() {
  val inputs = readln().split(' ').map{ it.toInt() }
  val n = inputs[0]
  val k = inputs[1]
  val a = readln().split(' ').map{ it.toInt() }
  val p = mutableListOf(0)
  for (i in 0..<n) {
    p.add(p.last() + a[i])
  }
  var ans = 0
  for (i in 0..n) {
    val len = n-i
    val can_take = len / k
    val free = p[i + can_take] - p[i]
    ans = Math.max(ans, free)
  }
  println(ans)
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
