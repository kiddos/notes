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

  sort(a.begin(), a.end());
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }

  double ans = numeric_limits<i64>::min();
  for (int i = 0; i < n-1; ++i) {
    double first = p[i+1], second = p[n] - p[i+1];
    double average = first / (i+1) + second / (n - i - 1);
    ans = max(ans, average);
  }
  cout << std::fixed << std::setprecision(8) << ans << endl;
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
