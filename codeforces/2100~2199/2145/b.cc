#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  int l = 0, r = n-1;
  int both = 0; 
  for (int i = 0; i < k; ++i) {
    if (s[i] == '0') {
      l++;
    } else if (s[i] == '1') {
      r--;
    } else if (s[i] == '2') {
      both++;
    }
  }
  int len = r-l+1;
  string ans(n, ' ');
  if (both >= len) {
    ans = string(n, '-');
  } else {
    for (int i = 0; i < n; ++i) {
      if (i < l || i > r) {
        ans[i] = '-';
      } else {
        if (i <= l+both-1 || i >= r-both+1) {
          ans[i] = '?';
        } else {
          ans[i] = '+';
        }
      }
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
