#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  if (n == 1) {
    cout << "-1" << endl;
    return;
  }

  set<int> s;
  for (int i = 1; i <= n; ++i) s.insert(i);

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    auto it = s.begin();
    if (*it == p[i] && s.size() > 1) {
      it = next(it);
    }
    ans[i] = *it;
    s.erase(it);
  }
  if (ans.back() == p.back()) {
    swap(ans[n-1], ans[n-2]);
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << endl;
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
