#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  sort(a.rbegin(), a.rend());
  multiset<int> s(b.begin(), b.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto it = s.upper_bound(a[i] + k);
    if (it != s.begin()) {
      --it;
      if (*it >= a[i] - k) {
        s.erase(it);
        ans++;
      }
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
