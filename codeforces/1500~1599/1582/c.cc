#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  constexpr int INF = numeric_limits<int>::max();

  auto try_symbol = [&](char ch) -> int {
    int l = 0, r = n-1;
    int ans = 0;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else {
        if (s[l] == ch) {
          ans++;
          l++;
        } else if (s[r] == ch) {
          ans++;
          r--;
        } else {
          return INF;
        }
      }
    }
    return ans;
  };

  int ans = INF;
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    int result = try_symbol(ch);
    ans = min(ans, result);
  }

  if (ans == INF) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
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
