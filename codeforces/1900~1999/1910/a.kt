fun solve() {
  val s = readln()
  var idx = s.length-1
  while (s.get(idx) == '0') {
    idx --
  }
  val ans = s.substring(0, idx)
  println(ans)
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
