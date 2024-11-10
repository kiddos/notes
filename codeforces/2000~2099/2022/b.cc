#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  i64 l = *max_element(a.begin(), a.end()), r = sum;
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 total_buy = mid * x;
    if (total_buy >= sum) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;;
    }
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
