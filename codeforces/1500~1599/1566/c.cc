#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0;
  vector<bool> used(n);
  int i = 0;
  while (i < n) {
    if (s1[i] != s2[i]) {
      ans += 2;
      i++;
    } else {
      if (s1[i] == '0') {
        if (i+1 < n && s1[i+1] == '1' && s2[i+1] == '1') {
          ans += 2;
          i += 2;
        } else {
          ans++;
          i++;
        }
      } else if (s1[i] == '1') {
        if (i+1 < n && s1[i+1] == '0' && s2[i+1] == '0') {
          ans += 2;
          i += 2;
        } else {
          i++;
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
