#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

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

i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1 = 0, y1 = 0;
  i64 d = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  i64 a = 10, b = 15;
  i64 x = 0, y = 0;
  i64 d = extended_euclidean(a, b, x, y);
  assert(d == 5);
  assert(a * x + b * y == d);
  return 0;
}
