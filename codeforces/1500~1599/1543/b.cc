#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  i64 ave = sum / n;
  vector<i64> b(n, ave);
  i64 left = sum - ave * n;
  i64 smaller = n - left;
  i64 ans = smaller * left;
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
