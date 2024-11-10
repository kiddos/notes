fun solve() {
  val (n, k) = readln().trim().split(" ").map(String::toLong)
  var ans = 0
  for (b in n downTo 0) {
    val mask = (1L shl b.toInt()) - 1
    if ((mask and k) > 0L) {
      ans++;
    } else {
      break;
    }
  }
  println(ans)
}

fun main() {
  val t = readln().toInt()
  for (i in 0..<t) {
    solve()
  }
}
