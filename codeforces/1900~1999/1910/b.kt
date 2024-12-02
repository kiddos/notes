fun swap(s: CharArray, i1: Int, i2: Int) {
  val c = s[i1]
  s[i1] = s[i2]
  s[i2] = c
}

fun solve() {
  val s = readln().toCharArray()
  var lastIn = -1;
  for (i in 0 until s.size) {
    if (s[i] == '+') {
      lastIn = i
    }
  }
  var b = 0
  var i1 = 1
  var i2 = 1
  for (i in 0 until s.size) {
    if (s[i] == '+') {
      b++
    } else if (s[i] == '-') {
      if (b > 0) {
        b--
      } else {
        if (i < lastIn) {
          if (i1 == i2) {
            swap(s, i, lastIn)
            b++
            i1 = i+1
            i2 = lastIn+1
          } else {
            println("-1")
            return
          }
        } else {
          println("-1")
          return
        }
      }
    }
  }
  println("$i1 $i2")
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
