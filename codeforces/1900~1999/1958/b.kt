fun solve() {
  val (k, m) = readln().trim().split(" ").map(String::toLong)
  val cycleSize = k * 3
  val c = (m + cycleSize - 1) / cycleSize
  val n = c * cycleSize
  val l = n - k
  if (m >= l && m < n) {
    println("0")
  } else {
    var wait = l - m;
    if (wait < 0) {
      wait += cycleSize;
    }
    println("$wait")
  }
}

fun main() {
  val t = readln().toInt()
  for (i in 0..<t) {
    solve()
  }
}
