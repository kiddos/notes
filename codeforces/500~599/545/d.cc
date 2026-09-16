#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  multiset<i64> s(t.begin(), t.end());
  i64 wait = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto it = s.lower_bound(wait);
    if (it == s.end()) {
      break;
    }
    wait += *it;
    s.erase(it);
    ans ++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
