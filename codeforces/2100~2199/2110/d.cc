#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  vector<int> s(m), t(m), w(m);
  for (int i = 0; i < m; ++i) {
    cin >> s[i] >> t[i] >> w[i];
  }
  vector<vector<pair<int,int>>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    adj[s[i]].push_back({t[i], w[i]});
  }

  auto possible = [&](int k) -> bool {
    set<pair<int,int>> s;
    s.insert({0, 1});
    constexpr int inf = numeric_limits<int>::max();
    vector<int> dist(n+1, inf);
    dist[1] = 0;
    while (!s.empty()) {
      auto [neg_b, checkpoint] = *s.begin();
      int battery = -neg_b;
      s.erase(s.begin());

      if (battery < k) {
        int can_add = min(k-battery, b[checkpoint]);
        battery += can_add;
      }

      for (auto [next_checkpoint, w] : adj[checkpoint]) {
        if (w > battery) {
          continue;
        }

        if (-battery < dist[next_checkpoint]) {
          s.erase({dist[next_checkpoint], next_checkpoint});
          dist[next_checkpoint] = -battery;
          s.insert({-battery, next_checkpoint});
        }
      }
    }
    return dist[n] < inf;
  };

  int l = 0, r = 0;
  for (int i = 0; i < m; ++i) {
    r = max(r, w[i]);
  }

  int ans = -1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
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
