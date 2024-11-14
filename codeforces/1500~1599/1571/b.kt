fun solve() {
  val n = readln().toInt()
  val (a, va) = readln().split(' ').map { it.toInt() }
  val (c, vc) = readln().split(' ').map { it.toInt() }
  val b = readln().toInt()

  val daysBefore = b - a
  val daysAfter = c - b
  for (vb in va..vc) {
    val needToReadBefore = vb - va
    val needToReadAfter = vc - vb
    if (needToReadBefore <= daysBefore && needToReadAfter <= daysAfter) {
      println(vb)
      return
    }
  }
}

fun main() {
  val t = readln().toInt()
  for (i in 1..t) {
    solve()
  }
}
