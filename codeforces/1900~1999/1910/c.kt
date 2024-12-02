fun solve() {
  val n = readln().toInt()
  val s1 = readln().toCharArray()
  val s2 = readln().toCharArray()
  var i = 0
  var ans = 0
  while (i < n) {
    var j = i
    while (j+1 < n && s1[j+1] == s1[i]) {
      j++
    }
    val len = j-i+1
    ans += len-1
    i = j+1
  }
  println("$ans")
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
