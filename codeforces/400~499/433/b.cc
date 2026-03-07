#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> v(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  vector<i64> u = v;
  sort(u.begin(), u.end());
  vector<i64> pv = v, pu = u;
  for (int i = 1; i <= n; ++i) {
    pv[i] += pv[i-1];
    pu[i] += pu[i-1];
  }

  int m = 0;
  cin >> m;
  vector<i64> ans;
  for (int i = 0; i < m; ++i) {
    int type = 0, l = 0, r = 0;
    cin >> type >> l >> r;
    if (type == 1) {
      ans.push_back(pv[r] - pv[l-1]);
    } else if (type == 2) {
      ans.push_back(pu[r] - pu[l-1]);
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
