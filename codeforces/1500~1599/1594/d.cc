#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<pair<int,int>>> adj(n+1);
  for (int k = 0; k < m; ++k) {
    int i = 0, j = 0;
    string c;
    cin >> i >> j >> c;
    int imposter = c == "imposter" ? 1 : 0;
    adj[j].emplace_back(i, imposter);
    adj[i].emplace_back(j, imposter);
  }

  function<int(int,int,vector<int>&)> dfs = [&](int p, int imposter, vector<int>& state) -> int {
    if (state[p] >= 0) {
      if (state[p] != imposter) {
        return -1;
      }
      return 0;
    }

    state[p] = imposter;

    int ans = 0;
    if (imposter) ans++;
    for (auto& [p2, imp] : adj[p]) {
      int result = dfs(p2, imp ^ imposter, state);
      if (result < 0) {
        return result;
      }
      ans += result;
    }
    return ans;
  };

  vector<int> states1(n+1, -1), states2(n+1, -1);
  int ans = 0;
  for (int p = 1; p <= n; ++p) {
    if (states1[p] >= 0) continue;

    int result = max(dfs(p, 1, states1), dfs(p, 0, states2));
    // cout << "result=" << result << endl;
    if (result < 0) {
      cout << "-1" << endl;
      return;
    }
    ans += result;
  }

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
