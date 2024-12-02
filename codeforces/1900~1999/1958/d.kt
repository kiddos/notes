fun solve() {
  val n = readln().toInt()
  val a = readln().trim().split(" ").map(String::toLong)
  var i = 0
  var ans = 0L
  while (i < n) {
    if (a[i] > 0) {
      val b = mutableListOf(a[i])
      var j = i
      while (j+1 < n && a[j+1] > 0) {
        j++
        b.add(a[j])
      }

      val len = b.size
      val sum = b.sum()
      if (len % 2 == 1) {
        var maxVal = 0L
        for (j in 0 until b.size step 2) {
          maxVal = Math.max(maxVal, b[j])
        }
        ans += sum * 2 - maxVal
      } else {
        ans += sum * 2
      }
      i = j + 1
    } else {
      i++
    }
  }
  println("$ans")
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
