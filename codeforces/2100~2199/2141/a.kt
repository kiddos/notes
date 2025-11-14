fun solve() {
  val n = readln().toInt()
  val a = readln().split(" ").map { it.trim().toInt() }.toIntArray()
  var min_val = Int.MAX_VALUE
  val ans = mutableListOf<Int>()
  for ((i, ai) in a.withIndex()) {
    min_val = minOf(min_val, ai)
    if (ai > min_val) {
      ans.add(i+1)
    }
  }

  println("${ans.size}")
  for (idx in ans) {
    print("${idx} ")
  }
  println()
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
