#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 f = 0, a = 0, b = 0;
  cin >> n >> f >> a >> b;
  vector<int> m(n);
  for (int i = 0; i < n; ++i) cin >> m[i];
  sort(m.begin(), m.end());

  int last = 0;
  int current = f;
  for (int i = 0; i < n; ++i) {
    i64 require = min((m[i] - last) * a, b);
    if (require >= current) {
      cout << "NO" << endl;
      return;
    }

    last = m[i];
    current -= require;
  }
  cout << "YES" << endl;
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
