#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int right_upper = 0;
  for (int i = 0; i < n; ++i) {
    right_upper += (isupper(s[i]) ? 1 : 0);
  }
  int left_upper = 0;
  int ans = n;
  for (int i = 0; i < n; ++i) {
    int u = isupper(s[i]) ? 1 : 0;
    left_upper += u;
    right_upper -= u;
    int left_lower = (i+1) - left_upper;
    int right_lower = (n-i-1) - right_upper;
    // change to left upper + right lower
    ans = min(ans, left_lower + right_upper);
    // change to all upper
    ans = min(ans, left_lower + right_lower);
    // change to all lower
    ans = min(ans, left_upper + right_upper);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
