#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  vector<i64> y = x;
  sort(y.begin(), y.end());
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + y[i]);
  }

  map<i64, i64> results;
  for (int i = 0; i < n; ++i) {
    if (results.count(y[i])) continue;

    i64 result = ((i+1) * (y[i]+1) - p[i+1]) + (p[n] - p[i] + (n-i) - (n-i) * y[i]) - 1;
    results[y[i]] = result;
  }

  for (int i = 0; i < n; ++i) {
    cout << results[x[i]] << " ";
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
