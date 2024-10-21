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

  int ans = 0;
  for (int w = 2; w <= 100; ++w) {
    multiset<int> found;
    int total_pair = 0;
    for (int i = 0; i < n; ++i) {
      auto it = found.find(w-a[i]);
      if (it != found.end()) {
        found.erase(it);
        total_pair++;
      } else {
        found.insert(a[i]);
      }
    }

    ans = max(ans, total_pair);
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
