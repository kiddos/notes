fun bobCanWin(a: IntArray, b: IntArray): Boolean {
  var win = 0
  var aliceTotal = 0
  var bobTotal = 0
  for (i in 0 until 3) {
    if (b[i] > a[i]) {
      win++
    }
    aliceTotal += a[i]
    bobTotal += b[i]
  }
  if (bobTotal > aliceTotal) {
    return true
  }
  if (bobTotal == aliceTotal && win >= 2) {
    return true
  }
  return false
}

fun solve() {
  val k = readln().toInt()
  val inputs1 = readln().split(' ').map{ it.toInt() }
  val a1 = inputs1[0]
  val b1 = inputs1[1]
  val inputs2 = readln().split(' ').map{ it.toInt() }
  val a2 = inputs2[0]
  val b2 = inputs2[1]
  for (a3 in 0..k) {
    for (b3 in 0..k) {
      val aliceScores = intArrayOf(a1, a2, a3)
      val bobScores = intArrayOf(b1, b2, b3)
      if (bobCanWin(aliceScores, bobScores)) {
        println("YES")
        return
      }
    }
  }
  println("NO")
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
