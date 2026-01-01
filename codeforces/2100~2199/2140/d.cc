#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += y[i] - x[i];
  }
  vector<pair<i64,i64>> adds;
  for (int i = 0; i < n; ++i) {
    adds.push_back({y[i] + x[i], i});
  }
  sort(adds.begin(), adds.end());
  if (n % 2 == 0) {
    int remove = n / 2;
    for (int i = 0; i < n; ++i) {
      ans += y[i];
    }
    for (int i = 0; i < remove; ++i) {
      ans -= adds[i].first;
    }
  } else {
    i64 extra1 = 0;
    for (int i = 0; i < n; ++i) {
      extra1 += y[i];
    }
    int remove = (n+1) / 2;
    for (int i = 0; i < remove; ++i) {
      extra1 -= adds[i].first;
    }
    i64 extra2 = 0;
    for (int i = 0; i < remove; ++i) {
      int idx = adds[i].second;
      extra2 = max(extra2, extra1 + x[idx]);
    }
    for (int i = remove; i < n; ++i) {
      int idx = adds[i].second;
      extra2 = max(extra2, extra1 + adds[n/2].first - y[idx]);
    }
    ans += extra2;
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
