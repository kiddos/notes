#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  // count number of steps going up and down

  auto compute = [&]() -> int {
    int max_val = a[0];
    int min_val = a[0];
    int flag = 2;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] > max_val) {
        max_val = a[i];
        if (flag) {
          flag = 0;
          ans++;
        }
      }
      if (a[i] < min_val) {
        min_val = a[i];
        if (flag ^ 1) {
          flag = 1;
          ans++;
        }
      }
    }
    return ans;
  };

  int ans = compute();
  reverse(a.begin(), a.end());
  ans += compute();
  cout << max(ans-1, 0) << endl;
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
