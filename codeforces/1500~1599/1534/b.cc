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
  int last = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += abs(last - a[i]);
    last = a[i];
  }
  ans += last;

  for (int i = 0; i < n; ++i) {
    int prev_a = i > 0 ? a[i-1] : 0;
    int next_a = i + 1 < n ? a[i+1] : 0;
    if (a[i] > prev_a && a[i] > next_a) {
      ans -= (a[i] - max(prev_a, next_a));
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
