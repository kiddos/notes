#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> diff;
  for (int i = 1; i < n; ++i) {
    diff.push_back(abs(a[i] - a[i-1]));
  }

  sort(diff.begin(), diff.end());
  for (int i = 0; i < k-1; ++i) diff.pop_back();
  int ans = accumulate(diff.begin(), diff.end(), 0);
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
