#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  int l = 0, r = n-1;
  if (n % 2 == 0) {
    r = n / 2;
    l = r-1;
  } else {
    r = n / 2;
    l = r;
  }
  while (r+1 < n && s[r+1] == s[r]) r++;
  while (l-1 >= 0 && s[l-1] == s[l]) l--;
  ans = r-l+1;

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
