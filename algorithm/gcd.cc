#include <bits/stdc++.h>

using namespace std;

// Euclidean algorithm
// psuedo code
//
// function gcd(a, b)
//   while b ≠ 0
//       t ← b
//       b ← a mod b
//       a ← t
//   return a

int iterative_gcd(int a, int b) {
  while (b != 0) {
    int next_a = b;
    b = a % b;
    a = next_a;
  }
  return a;
}

int recursive_gcd(int a, int b) {
  if (b == 0) return a;
  return recursive_gcd(b, a % b);
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  assert(iterative_gcd(12, 18) == 6);
  assert(recursive_gcd(12, 18) == 6);

  assert(iterative_gcd(11, 17) == 1);
  assert(recursive_gcd(11, 17) == 1);

  assert(lcm(10, 20) == 20);
  assert(lcm(16, 22) == 176);
  return 0;
}
