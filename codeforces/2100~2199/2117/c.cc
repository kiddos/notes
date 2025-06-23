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

  int i = 1;
  set<int> s = {a[0]};
  int ans = 1;
  while (i < n) {
    int j = i;
    set<int> s2;
    while (j < n && s.size() > 0) {
      s.erase(a[j]);
      s2.insert(a[j]);
      j++;
    }
    if (s.empty()) {
      ans++;
    }
    s = std::move(s2);
    i = j;
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
