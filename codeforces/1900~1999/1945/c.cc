#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// #1#0#1#
// #1#1#0#0#

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int right = 0;
  for (int i = 0; i < n; ++i) right += s[i] == '1';

  string s2 = "#";
  for (char ch : s) {
    s2.push_back(ch);
    s2.push_back('#');
  }

  int ans = -1;
  int left = 0;
  int m = s2.length();
  for (int i = 0; i < m; ++i) {
    left += s2[i] == '0';
    right -= s2[i] == '1';

    if (s2[i] == '#') {
      if (left * 2 >= i/2 && right * 2 >= (m-i) / 2) {
        if (ans == -1 || abs(m/2 - i) < abs(m/2 - ans)) {
          ans = i;
        } 
      }
    }
  }

  cout << (ans + 1) / 2 << endl;
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
