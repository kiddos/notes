#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> p10(11, 1);

void precompute() {
  for (int i = 1; i <= 10; ++i) {
    p10[i] = p10[i-1] * 10;
  }
}

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  k++;

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i == n-1) {
      ans += k * p10[a[i]];
    } else {
      int can_take = a[i+1] - a[i];
      i64 count = min(p10[can_take]-1, k);
      ans += count * p10[a[i]];
      k -= count;
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
