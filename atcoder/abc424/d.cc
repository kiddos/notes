#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int inf = 1e9;

void solve() {
  int h = 0, w = 0;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; ++i) {
    cin >> s[i];
  }

  int m = 1<<w;
  vector<int> dp(m);

  auto count_ops = [&](int mask, int r) -> int {
    int ans = 0;
    for (int b = 0; b < w; ++b) {
      if (s[r][b] == '#') {
        if (!(mask & (1<<b))) {
          ans++;
        }
      } else if (s[r][b] == '.') {
        if (mask & (1<<b)) {
          return inf;
        }
      }
    }
    return ans;
  };

  for (int mask = 0; mask < m; ++mask) {
    dp[mask] = count_ops(mask, 0);
  }

  auto valid = [&](int mask1, int mask2) -> bool {
    for (int b = 1; b < w; ++b) {
      int b1 = 1<< (b-1);
      int b2 = 1<< b;
      if ((mask1 & b1) && (mask1 & b2) && (mask2 & b1) && (mask2 & b2)) {
        return false;
      }
    }
    return true;
  };

  for (int i = 1; i < h; ++i) {
    vector<int> dp2(m, inf);
    for (int mask1 = 0; mask1 < m; ++mask1) {
      if (dp[mask1] >= inf) {
        continue;
      }

      for (int mask2 = 0; mask2 < m; ++mask2) {
        int op = count_ops(mask2, i);
        if (op >= inf) {
          continue;
        }

        if (!valid(mask1, mask2)) {
          continue;
        }
        dp2[mask2] = min(dp2[mask2], dp[mask1] + op);
      }
    }
    dp = std::move(dp2);
  }

  int ans = *min_element(dp.begin(), dp.end());
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
