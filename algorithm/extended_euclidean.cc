#include <bits/stdc++.h>

using namespace std;

// euclidean algorithm only finds gcd(a, b)
// extended_euclidean finds a * x + b * y = gcd(a, b)
// a * x + b * y = g
// => a * x1 + b * y1 = g
// => b * x2 + (a % b) * y2 = g
// => a * x1 + b * y1 = b * x2 + (a - a / b * b) * y2
// => a * x1 + b * y1 = a * y2 + (b * x2 - a / b * b * y2) 
// => a * x1 + b * y1 = a * y2 + b * (x2 - a / b * y2);
//
// => x1 = y2
// => y1 = x2 - a / b * y2;

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
