#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  vector<i64> p = {0};
  for (int i = 0; i < m; ++i) {
    p.push_back(p.back() + a[i]);
  }
  vector<i64> s(m+1);
  for (int i = 0; i < m; ++i) {
    s[i] = max(a[i] - n + 1, 0);
  }
  for (int i = m-1; i >= 0; --i) {
    s[i] += s[i+1];
  }

  i64 ans = 0;
  for (int i = 0; i < m; ++i) {
    int idx = lower_bound(a.begin()+i+1, a.end(), n-a[i]) - a.begin();
    i64 suffix_sum = p[m] - p[idx];
    i64 count = m - idx;
    i64 ways = suffix_sum + (a[i] + 1) * count - n * count
      - max(a[i] - n + 1, 0) * count - s[idx];
    ans += ways * 2;
  }

  // for (int i = 0; i < m; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     if (i != j && a[i] + a[j] >= n) {
  //       i64 len = a[i] + a[j];
  //       i64 ways = len-n+1 - max(a[i] - n + 1, 0) - max(a[j] - n + 1, 0);
  //       ans += ways;
  //     }
  //   }
  // }
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
