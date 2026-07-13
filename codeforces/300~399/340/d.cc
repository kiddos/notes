#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<int> s;
  for (int i = 0; i < n; ++i) {
    auto it = s.lower_bound(a[i]);
    if (it != s.end()) {
      s.erase(it);
    }
    s.insert(a[i]);
  }
  int ans = s.size();
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
