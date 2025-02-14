#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, C = 0;
  cin >> n >> C;
  vector<int> c(n), d(n), h(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i] >> d[i] >> h[i];
  }

  vector<i64> base(C+1);
  for (int i = 0; i < n; ++i) {
    i64 unit_power = (i64) d[i] * h[i];
    base[c[i]] = max(base[c[i]], unit_power);
  }

  vector<i64> max_power(C+1);
  for (int cost = 1; cost <= C; ++cost) {
    i64 unit_power = base[cost];
    if (unit_power == 0) {
      continue;
    }
    for (int k = 1; k * cost <= C; ++k) {
      max_power[k * cost] = max(max_power[k * cost], unit_power * k);
    }
  }

  vector<i64> p = max_power;
  for (int i = 1; i <= C; ++i) {
    p[i] = max(p[i], p[i-1]);
  }

  int m = 0;
  cin >> m;
  vector<int> D(m);
  vector<i64> H(m);
  for (int j = 0; j < m; ++j) {
    cin >> D[j] >> H[j];
  }

  vector<int> ans(m, -1);
  for (int i = 0; i < m; ++i) {
    i64 monster_power = D[i] * H[i];
    auto it = lower_bound(p.begin(), p.end(), monster_power+1);
    if (it != p.end()) {
      ans[i] = it - p.begin();
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
