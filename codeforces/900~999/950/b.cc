#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  i64 sum1 = 0, sum2 = 0;
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    sum1 += a[i];
    while (j < m && sum2 + b[j] <= sum1) {
      sum2 += b[j++];
    }
    if (sum1 == sum2) {
      ans++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
