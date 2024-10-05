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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int min_a = *min_element(a.begin(), a.end());
  int min_b = *min_element(b.begin(), b.end());
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    i64 candy = a[i] - min_a;
    i64 orange = b[i] - min_b;
    i64 common = min(candy, orange);
    candy -= common;
    orange -= common;
    ans += common;
    ans += candy;
    ans += orange;
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
