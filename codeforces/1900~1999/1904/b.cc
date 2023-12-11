#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<pair<i64,int>> b;
  for (int i = 0; i < n; ++i) {
    b.emplace_back(a[i], i);
  }
  sort(b.begin(), b.end());
  vector<int> ans(n);
  i64 sum = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j <= i) {
      sum += b[j].first;
      j++;
    }
    while (j < n && b[j].first <= sum) {
      sum += b[j].first;
      j++;
    }
    ans[b[i].second] = j-1;
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
