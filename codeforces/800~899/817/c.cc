#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 diff(i64 x) {
  string s = to_string(x);
  i64 ans = x;
  for (char ch : s) {
    ans -= (ch - '0');
  }
  return ans;
}

void solve() {
  i64 n = 0, s = 0;
  cin >> n >> s;
  int max_t = 9 * 18;
  i64 ans = 0;
  for (int t = 1; t <= max_t && s+t <= n; ++t) {
    i64 diff_val = diff(s+t);
    if (diff_val >= s) {
      ans = n-(s+t)+1;
      break;
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
