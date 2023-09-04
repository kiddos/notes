#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  int ans = 0;
  vector<int> s;
  for (int i = 0; i < n; ++i) {
    int inv = 0;
    while (!s.empty() && p[s.back()] > p[i]) {
      s.pop_back();
      inv ++;
    }

    s.push_back(i);

    if (inv >= 1) {
      ans ++;
      s.clear();
    }
  }

  cout << ans << endl;
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
