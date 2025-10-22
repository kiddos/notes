#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  vector<vector<int>> slip_from(n+1);
  for (int x = 1; x <= n; ++x) {
    slip_from[x+b[x]].push_back(x);
  }

  set<int> positions;
  for (int i = 0; i <= n; ++i) {
    positions.insert(i);
  }

  constexpr int inf = 1e9;
  queue<int> q;
  vector<int> dp(n+1, inf);
  dp[n] = 0;
  positions.erase(n);

  vector<int> next(n+1, -1);
  for (int x = n-1; x >= max(n - a[n], 0); --x) {
    q.push(x);
    positions.erase(x);
    dp[x] = 1;
    next[x] = n;
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int x = q.front();
      q.pop();

      int x2 = x + b[x];
      int low = x2 - a[x2];
      for (auto it = positions.lower_bound(low); it != positions.end() && *it <= x2;) {
        int x3 = *it;
        q.push(x3);
        dp[x3] = dp[x] + 1;
        if (next[x3] < 0) {
          next[x3] = x;
        }
        it = positions.erase(it);
      }
    }
  }

  if (dp[0] >= inf) {
    cout << "-1" << endl;
    return;
  }

  // for (int i = 0; i <= n; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i <= n; ++i) {
  //   cout << next[i] << " ";
  // }
  // cout << endl;

  vector<int> ans;
  int p = 0;
  while (p < n) {
    ans.push_back(p);
    p = next[p];
  }

  cout << ans.size() << endl;
  reverse(ans.begin(), ans.end());
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;

  // constexpr int inf = 1e9;
  // vector<pair<int,int>> prev(n+1);
  // auto dp = [&](const auto& self, int x) -> int {
  //   if (x - a[x] <= 0) {
  //     prev[x] = {0, 0};
  //     return 1;
  //   }
  //   int ans = inf;
  //   for (int jump = a[x]; jump >= 0; --jump) {
  //     int p = x - jump + b[x-jump];
  //     if (p < x) {
  //       int result = self(self, p) + 1;
  //       if (result < ans) {
  //         ans = result;
  //         prev[x] = {p, x-jump};
  //       }
  //     }
  //   }
  //   return ans;
  // };
  //
  // int result = dp(dp, n);
  // if (result >= inf) {
  //   cout << "-1" << endl;
  //   return;
  // }
  //
  // vector<int> ans;
  // int p = n;
  // while (p >= 1) {
  //   auto [p2, after_jump] = prev[p];
  //   ans.push_back(after_jump);
  //   p = p2;
  // }
  //
  // cout << ans.size() << endl;
  // for (int d : ans) {
  //   cout << d << " ";
  // }
  // cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
