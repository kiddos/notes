#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + x[i]);
  }

  vector<i64> ans;
  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    ans.push_back(p[b] - p[a-1]);
  }

  for (i64 val : ans) {
    cout << val << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
