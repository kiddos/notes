#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  int dist = abs(b - a);
  int total = dist * 2;
  int d = c + dist > total ? c - dist : c + dist;
  if (a > total || b > total || c > total || d > total || d < 1) {
    cout << "-1" << endl;
    return;
  }
  cout << d << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
