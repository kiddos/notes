#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  i64 a_sum = accumulate(a.begin(), a.end(), 0LL);
  i64 b_sum = accumulate(b.begin(), b.end(), 0LL);
  i64 ans1 = a_sum + *min_element(b.begin(), b.end()) * n;
  i64 ans2 = b_sum + *min_element(a.begin(), a.end()) * n;

  i64 ans = min(ans1, ans2);
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
