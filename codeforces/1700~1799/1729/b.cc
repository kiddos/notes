#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  string ans;
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == '0' && i >= 2) {
      int d = (s[i-2] - '0') * 10 + s[i-1] - '0';
      i -= 2;
      ans.push_back(d + 'a' - 1);
    } else {
      int d = s[i] - '0';
      ans.push_back(d + 'a' - 1);
    }
  }

  reverse(ans.begin(), ans.end());
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
