#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0;
  cin >> a >> b;
  string sa = to_string(a);
  string sb = to_string(b);
  if (sa.length() < sb.length()) {
    sa = string(sb.length()-sa.length(), '0') + sa;
  }
  int n = sb.length();

  map<array<int,5>, i64> memo;
  auto dp = [&](const auto& self, int i, bool low, bool high, bool all_zero, int last_d) -> i64 {
    if (i == n) {
      return 1;
    }
    array<int,5> key = {i, (int)low, (int)high, (int)all_zero, last_d};
    if (memo.count(key)) {
      return memo[key];
    }

    int start = low ? sa[i]-'0' : 0;
    int end = high ? sb[i]-'0' : 9;
    i64 ans = 0;
    for (int d = start; d <= end; ++d) {
      if (d != last_d || all_zero) {
        i64 result = self(self, i+1, low && d == start, high && d == end, all_zero && d == 0, d);
        ans += result;
      }
    }
    return memo[key] = ans;
  };

  i64 ans = dp(dp, 0, true, true, true, -1);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
