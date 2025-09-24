fun pushAndPop(ans: ArrayDeque<String>, l: Int, r: Int) {
  for (i in l..r) {
    ans.add("pushback a[${i}]")
    ans.add("min")
  }
  for (i in l..r) {
    ans.add("popfront")
    ans.add("min")
  }
  ans.removeLast()
}

fun solve() {
  val n = readln().toInt()
  val ans = ArrayDeque<String>()

  var l = 0
  var r = n-1
  while (l <= r) {
    pushAndPop(ans, l, r)
    l++
    r--
  }

  println("${ans.size}")
  for (line in ans) {
    println(line)
  }
}

fun main() {
  solve()
}
