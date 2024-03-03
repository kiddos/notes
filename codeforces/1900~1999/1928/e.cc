#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// x = x % y + x / y * y
// a = [x % y + y * b0, x % y + b1, x % y + b2, ...]

void solve() {
  i64 n = 0, x = 0, y = 0, s = 0;
  cin >> n >> x >> y >> s;

  i64 m = x % y;
  s -= m * n;

  // cout << "base=" << m * n << endl;
  // cout << "rest=" << s << endl;

  if (s < 0 || s % y != 0) {
    cout << "NO" << endl;
    return;
  }

  int z = s / y;
  // cout << "z=" << z << endl;
  constexpr int INF = numeric_limits<int>::max();
  vector<int> dp(z+1, INF);
  vector<pair<int,int>> parent(z+1);
  for (i64 base = 1; base * (base-1) / 2 <= z; ++base) {
    i64 c2 = base * (base-1) / 2;
    dp[c2] = base;
    parent[c2] = {0, base};
  }
  for (int c = 0; c < z; ++c) {
    if (dp[c] < INF) {
      // I can add 0, (0+1), (0+1+2), (0+1+2+3)
      for (i64 base = 1; c+base * (base-1) / 2 <= z; ++base) {
        i64 c2 = c + base * (base-1) / 2;
        int min_len = dp[c] + (int)base;
        if (min_len < dp[c2]) {
          dp[c2] = min_len;
          parent[c2] = {c, base};
        }
      }
    }
  };

  // cout << "possible sum: " << endl;
  // for (int c = 0; c <= z; ++c) {
  //   cout << dp[c] << " ";
  // }
  // cout << endl;

  auto construct = [&](int b, int c) {
    vector<int> a;
    for (int bb = x/y; bb <= b; ++bb) {
      a.push_back(x % y + bb * y);
    }

    // cout << "c=" << c << endl;
    int cc = c;
    vector<int> rest;
    while (cc > 0) {
      auto [c2, base] = parent[cc];
      for (int b = base-1; b >= 0; --b) {
        rest.push_back(x % y + b * y);
      }
      while (!rest.empty()) {
        a.push_back(rest.back());
        rest.pop_back();
      }

      cc = c2;
    }

    while ((int)a.size() < n) {
      a.push_back(x % y);
    }

    for (int i = 0; i < (int)a.size(); ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
  };

  int b0 = x / y;
  i64 prefix = 0;
  for (int len = 1, b = b0; len <= n; ++len, ++b) {
    prefix += b;
    if (prefix > z) break;

    if (prefix == z || (prefix < z && dp[z-prefix] <= n-len)) {
      cout << "YES" << endl;
      // construct the array
      construct(b, z - prefix);
      return;
    }
  }
  cout << "NO" << endl;
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
