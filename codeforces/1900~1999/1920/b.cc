#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, x = 0;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());

  vector<int> b = {0};
  for (int i = 0; i < n; ++i) {
    b.push_back(b.back() - a[i]);
  }
  vector<int> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }

  auto get_answer = [&](int alice) {
    return b[n-alice] - b[max(n-alice-x, 0)] + p[max(n-alice-x, 0)];
  };

  int ans = get_answer(0);
  for (int i = 1; i <= k; ++i) {
    ans = max(ans, get_answer(i));
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
