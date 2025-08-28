#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> t(n+1), x(n+1);
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> x[i];
  }
  t[n] = numeric_limits<i64>::max();

  i64 current_pos = 0, current_time = 0;
  vector<array<i64,4>> path;
  for (int i = 0; i < n; ++i) {
    if (current_time <= t[i]) {
      i64 require_time = abs(current_pos - x[i]);
      path.push_back({t[i], t[i] + require_time, current_pos, x[i]});

      current_pos = x[i];
      current_time = t[i] + require_time;
    }
  }

  // cout << "path:" << endl;
  // for (auto [t1, t2, x1, x2]: path) {
  //   cout << t1 << "~" << t2 << ": " << x1 << "->" << x2 << endl;
  // }
  // cout << endl;

  auto is_successful = [&](array<i64,4>& p, int i) -> bool {
    i64 t1 = max(t[i], p[0]);
    i64 t2 = min(t[i+1], p[1]);
    if (t1 > t2) {
      return false;
    }

    i64 d = p[3] >= p[2] ? 1 : -1;
    i64 x1 = p[2] + (t1 - p[0]) * d;
    i64 x2 = p[2] + (t2 - p[0]) * d;
    // cout << t1 << "~" << t2 << ": " << x1 << "->" << x2 << ", x[i]=" << x[i] << endl;
    return min(x1, x2) <= x[i] && x[i] <= max(x1, x2);
  };

  int ans = 0;
  int m = path.size();
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < m && path[j][1] < t[i]) {
      j++;
    }
    if (j < m) {
      if (is_successful(path[j], i) || (j+1 < m && is_successful(path[j+1], i))) {
        ans++;
      }
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
