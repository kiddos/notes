#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, c = 0;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  constexpr int inf = 1e9;
  auto reduce_only = [&]() -> int {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] < b[i]) {
        return inf;
      }
      ans += a[i] - b[i];
    }
    return ans;
  };

  auto reduce_and_sort = [&]() -> int {
    vector<int> x = a;
    vector<int> y = b;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (x[i] < y[i]) {
        return inf;
      }
      ans += x[i] - y[i];
    }
    return ans + c;
  };

  int ans = min(reduce_only(), reduce_and_sort());
  if (ans >= inf) {
    cout << "-1" << endl;
    return;
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
