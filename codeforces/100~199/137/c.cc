#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  map<int,int> begins;
  for (int i = 0; i < n; ++i) {
    begins[b[i]] = a[i];
  }

  for (auto it = next(begins.rbegin()); it != begins.rend(); ++it) {
    auto last_it = prev(it);
    it->second = min(it->second, last_it->second);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto it = begins.lower_bound(b[i]+1);
    if (it != begins.end() && it->second < a[i]) {
      ans++;
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
