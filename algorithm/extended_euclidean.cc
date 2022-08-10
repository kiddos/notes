#include <bits/stdc++.h>

using namespace std;

// euclidean algorithm only finds gcd(a, b)
// extended_euclidean finds a * x + b * y = gcd(a, b)

int extended_euclidean(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  int x1 = 0, y1 = 0;
  int d = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a = 10, b = 15;
  int x = 0, y = 0;
  int d = extended_euclidean(a, b, x, y);
  assert(d == 5);
  assert(a * x + b * y == d);
  return 0;
}
