#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define PI 3.14159265358979323846264338327950288

void solve() {
  int n = 0, r = 0;
  cin >> n >> r;
  // cos(a) = (B^2 + C^2 - A^2) / (2 * B * C)
  // B = r + x, C = r + x, A = 2x
  // a = 2*pi / n
  // cos(a) = (r^2 + 2xr + x^2 + r^2 + 2xr + x^2 - 4x^2) / (2 * (r^2 + 2xr + x^2))
  // 2cos(a) * (r^2 + 2xr + x^2) = (2r^2 + 4xr - 2x^2)
  // => cos(a) * (r^2 + 2xr + x^2) = (r^2 + 2xr - x^2)
  // => (cos(a) + 1) x^2 + (2cos(a) - 2)xr + (cos(a)r^2 - r^2) = 0

  double angle = 2.0 * PI / n;
  double b = (cos(angle) * 2.0 - 2.0) * r;
  double a = (cos(angle) + 1.0);
  double c = (cos(angle) * r * r - r * r);
  double ans = (-b + sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
  cout << fixed << setprecision(8) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
