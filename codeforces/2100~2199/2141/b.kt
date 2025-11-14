fun solve() {
  val sizes = readln().split(" ").map { it.trim().toInt() }.toIntArray()
  val n = sizes[0]
  val m = sizes[1]
  val a = readln().split(" ").map { it.trim().toInt() }.toIntArray()
  val b = readln().split(" ").map { it.trim().toInt() }.toIntArray()
  val a_has = HashSet<Int>()
  for (ai in a) {
    a_has.add(ai)
  }
  val common = HashSet<Int>()
  for (bi in b) {
    if (a_has.contains(bi)) {
      common.add(bi)
    }
  }

  val a1 = ArrayDeque<Int>()
  val a2 = ArrayDeque<Int>()
  for (ai in a) {
    if (common.contains(ai)) {
      a2.add(ai)
    } else {
      a1.add(ai)
    }
  }

  val b1 = ArrayDeque<Int>()
  val b2 = ArrayDeque<Int>()
  for (bi in b) {
    if (common.contains(bi)) {
      b2.add(bi)
    } else {
      b1.add(bi)
    }
  }

  var ans = 0
  for (i in 0..(n+m)) {
    if (i % 2 == 0) {
      // Alice
      if (!a1.isEmpty()) {
        a1.removeFirst()
        ans++
      } else if (!a2.isEmpty()) {
        a2.removeFirst()
        ans++
        break
      }
    } else {
      // Bob
      if (!b1.isEmpty()) {
        b1.removeFirst()
        ans++
      } else if (!b2.isEmpty()) {
        b2.removeFirst()
        ans++
        break
      }
    }
  }
  println("${ans}")
}

fun main() {
  val n = readln().toInt()
  for (i in 0..<n) {
    solve()
  }
}
