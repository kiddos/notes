#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

void solve() {
  int n = 0;
  cin >> n;
  int m = n * 2;
  vector<int> c(m);
  for (int i = 0; i < m; ++i) cin >> c[i];

  vector<int> last(m+1, -1);
  int ans1 = 0;
  i64 ans2 = 1;
  vector<array<int, 3>> s;
  for (int i = 0; i < m; ++i) {
    if (last[c[i]] < 0) {
      last[c[i]] = i;
      s.push_back({i, 1, 1});
    } else {
      int count = 1;
      int end = -1;
      int l = last[c[i]];
      while (!s.empty() && s.back()[0] > l) {
        count += s.back()[1];
        end += s.back()[2];
        s.pop_back();
      }
      s.back()[1] += count;
      s.back()[2] += end;

      if (s.back()[2] == 0) {
        i64 count = s.back()[1];
        s.pop_back();
        if (s.empty()) {
          ans1 ++;
          ans2 *= count;
          ans2 %= MOD;
        }
      }
    }
  }

  cout << ans1 << " " << ans2 << endl;
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
