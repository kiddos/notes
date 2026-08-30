#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = i, r = i;
    int diff = 0;
    while (l >= 0 && r < n && (diff == 0 || s[l] == s[r])) {
      diff += (s[l] != s[r]);
      l--;
      r++;
    }
    int len = r-l-1;
    ans += (len+1) / 2;

    // cout << "i=" << i << ", len=" << len << ",l=" << l << ",r=" << r << endl;

    if (i+1 < n) {
      l = i, r = i+1;
      diff = s[l] != s[r];
      l--;
      r++;
      while (l >= 0 && r < n && (diff == 0 || s[l] == s[r])) {
        diff += (s[l] != s[r]);
        l--;
        r++;
      }
      len = r-l-1;
      ans += len / 2;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
