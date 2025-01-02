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

  map<int, vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    indices[a[i]].push_back(i);
  }

  i64 ans = 0;
  for (auto [x, idx] : indices) {
    int size = idx.size();
    vector<i64> suffix(size+1);
    for (int i = size-1; i >= 0; --i) {
      suffix[i] = n - idx[i];
      suffix[i] += suffix[i+1];
    }
    for (int i = 0; i+1 < size; ++i) {
      i64 total = ((i64)idx[i] + 1) * suffix[i+1];
      ans += total;
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
