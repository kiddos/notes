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
  string s;
  cin >> s;

  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(a[i] + p.back());
  }

  int l = 0, r = n-1;
  i64 ans = 0;
  while (l < r) {
    while (l < r && s[l] != 'L') l++;
    while (r > l && s[r] != 'R') r--;
    if (l >= r) break;
    ans += p[r+1] - p[l];
    l++;
    r--;
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
