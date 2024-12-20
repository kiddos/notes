#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());

  int min_diff = numeric_limits<int>::max();
  int start = 0;
  for (int i = 1; i < n; ++i) {
    int diff = h[i] - h[i-1];
    if (diff < min_diff) {
      start = i-1;
      min_diff = diff;
    }
  }
  vector<int> ans(n);
  ans[0] = h[start];
  ans.back() = h[start+1];
  int k = 1;
  for (int i = start+2; i < n; ++i, ++k) {
    ans[k] = h[i];
  }
  for (int i = 0; i < start; ++i, ++k) {
    ans[k] = h[i];
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
