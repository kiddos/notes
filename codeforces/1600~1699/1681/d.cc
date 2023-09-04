#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 power(int a, int n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= a;
    }
    a = a * a;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  i64 x0 = 0;
  cin >> x0;

  map<array<int,4>, int> memo;
  constexpr int INF = 1e9;
  function<int(int,int,int,int)> dp = [&](int a, int b, int c, int d) -> int {
    array<int,4> key = {a, b, c, d};
    if (memo.count(key)) {
      return memo[key];
    }

    i64 x = x0 * power(2, a) * power(3, b) * power(5, c) * power(7, d);
    string s = to_string(x);
    if (s.length() >= n) {
      return memo[key] = 0;
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int ans = INF;
    for (char ch : s) if (ch >= '2') {
      int y = ch - '0';
      int a2 = a, b2 = b, c2 = c, d2 = d;
      while (y % 2 == 0) {
        a2++;
        y /= 2;
      }
      while (y % 3 == 0) {
        b2++;
        y /= 3;
      }
      while (y % 5 == 0) {
        c2++;
        y /= 5;
      }
      while (y % 7 == 0) {
        d2++;
        y /= 7;
      }
      // cout << y << ": " << a2 << " " << b2 << " " << c2 << " " << d2 << endl;
      ans = min(ans, dp(a2, b2, c2, d2)+1);
    }

    return memo[key] = ans;
  };

  int ans = dp(0, 0, 0, 0);
  if (ans >= INF) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
