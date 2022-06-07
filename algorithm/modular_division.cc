#include <bits/stdc++.h>

using namespace std;

int extended_euclid(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  int x1 = 0, y1 = 0;
  int g = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

int mod_div(int a, int b, int m) {
  int x = 0, y = 0;
  int g = extended_euclid(b, m, x, y);
  if (g != 1) {
    return -1;
  } else {
    int inv_b = (x % m + m) % m;
    return (a * inv_b) % m;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a = 8, b = 3, m = 5;
  int ans = mod_div(a, b, m);
  assert(ans == 1);

  a = 8, b = 4, m = 5;
  ans = mod_div(a, b, m);
  assert(ans == 2);

  a = 11, b = 4, m = 5;
  ans = mod_div(a, b, m);
  assert(ans == 4);
  return 0;
}
