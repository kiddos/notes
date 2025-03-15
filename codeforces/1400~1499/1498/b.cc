#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, W = 0;
  cin >> n >> W;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  multiset<int> s(w.begin(), w.end());

  int ans = 1;
  int size = W;
  while (!s.empty()) {
    auto it = s.upper_bound(size);
    if (it == s.begin()) {
      ans++;
      size = W;
    } else {
      --it;
      size -= *it;
      s.erase(it);
    }
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
