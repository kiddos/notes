#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 2 ^ (ai) + 2 ^ (aj) > 2 ^ (ak)
// so if aj >= ak or ai >= ak
// it will work?

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int,i64> counts;
  for (int i = 0; i < n; ++i) {
    counts[a[i]]++;
  }

  i64 ans = 0;
  i64 smaller = 0;
  for (auto& [_, c] : counts) {
    ans += c * (c-1) * (c-2) / 6;
    ans += c * (c-1) * smaller / 2;
    smaller += c;
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
