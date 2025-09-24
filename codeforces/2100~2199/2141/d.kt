fun solve() {
  val inputs = readln().split(" ").map { it.trim().toLong() }.toLongArray()
  val n = inputs[0]
  val k = inputs[1]
  val a = readln().split(" ").map { it.trim().toLong() }.toLongArray()
  a.sort()
  val maxVal = a.last()

  var p = 0L
  for (ai in a) {
    p += ai
  }

  var l = maxVal
  var r = 1000000000000L
  var x = -1L
  while (l <= r) {
    val mid = l + (r-l) / 2
    val ops = mid * n - p
    if (ops <= k) {
      l = mid + 1
      x = mid
    } else {
      r = mid - 1
    }
  }

  if (x < 0) {
    println("-1")
    return;
  }

  var ans = 0L
  for ((i, ai) in a.withIndex()) {
    if (i > 0) {
      if (ai == a[0]) {
        ans += Math.max(x - ai -1, 0L);
      } else {
        ans += x - ai
      }
    }
  }
  println(ans)
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
