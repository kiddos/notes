#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  int m = 0;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  auto prefix_max = [&](vector<int>& arr) -> i64 {
    int size = arr.size();
    i64 ans = 0;
    i64 p = 0;
    for (int i = 0; i < size; ++i) {
      p += arr[i];
      ans = max(ans, p);
    }
    return ans;
  };

  i64 ans = prefix_max(r) + prefix_max(b);
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
