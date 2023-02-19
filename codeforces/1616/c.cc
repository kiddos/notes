#include <bits/stdc++.h>

using namespace std;

struct Line {
  int a, b, c;
};

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

Line compute_line(int x1, int y1, int x2, int y2) {
  int delta_y = y1 - y2;
  int delta_x = x2 - x1;
  int g = gcd(abs(delta_y), abs(delta_x));
  int a = delta_y / g;
  int b = delta_x / g;
  int c = -a * x1 - b * y1;
  return Line{a, b, c};
}

int solve(vector<int>& y) {
  int n = y.size();
  if (n <= 2) return 0;
  int ans = 0;
  for (int x1 = 0; x1 < n; ++x1) {
    for (int x2 = x1+1; x2 < n; ++x2) {
      auto [a, b, c] = compute_line(x1, y[x1], x2, y[x2]);
      int on_line = 0;
      for (int x = 0; x < n; ++x) {
        if (a * x + b * y[x] + c == 0) {
          on_line++;
        }
      }
      ans = max(ans, on_line);
    }
  }
  return n - ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = solve(a);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
