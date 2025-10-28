#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }
  multiset<int> h;
  for (int i = 0; i < n; ++i) {
    auto it = h.upper_bound(k[i]);
    if (it != h.end()) {
      h.erase(it);
    }
    h.insert(k[i]);
  }
  int ans = h.size();
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
