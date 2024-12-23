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

  vector<i64> sum(2);
  vector<int> count(2);
  for (int i = 0; i < n; ++i) {
    sum[i%2] += a[i];
    count[i%2]++;
  }
  if (sum[0] % count[0] != 0 || sum[1] % count[1] != 0) {
    cout << "NO" << endl;
    return;
  }
  int val1 = sum[0] / count[0];
  int val2 = sum[1] / count[1];
  if (val1 != val2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
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
