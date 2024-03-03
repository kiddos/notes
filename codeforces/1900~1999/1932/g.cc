#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  i64 x1 = 0, y1 = 0;
  i64 g = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

i64 mod_inv(i64 a, i64 mod) {
  i64 x = 0, y = 0;
  extended_euclidean(a, mod, x, y);
  return (x + mod) % mod;
}

i64 solve_for_kprime(i64 d1, i64 d2, i64 H) {
  i64 inv_s = mod_inv(d2, H);
  i64 k = d1 * inv_s;
  return k % H;
}

i64 solve_for_k(i64 l1, i64 l2, i64 s1, i64 s2, i64 H) {
  i64 s_diff = (s2 - s1 + H) % H;
  i64 g = gcd(s_diff, H);
  i64 l_diff = ((l1 - l2 + H) % H);
  if (g > 1) {
    l_diff /= g;
    s_diff /= g;
    H /= g;
  }
  return solve_for_kprime(l_diff, s_diff, H);
}

void solve() {
  int n = 0, m = 0;
  i64 H = 0;
  cin >> n >> m >> H;

  vector<i64> l(n);
  for (int i = 0; i < n; ++i) cin >> l[i];
  vector<i64> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  constexpr i64 INF = numeric_limits<i64>::max();
  vector<i64> dist(n, INF);
  dist[0] = 0;

  set<array<i64,2>> q;
  q.insert({0, 0});
  while (!q.empty()) {
    auto [step, platform] = *q.begin();
    q.erase(q.begin());

    if (platform == n-1) {
      break;
    }

    // cout << "platform=" << platform << endl;
    i64 s1 = s[platform];
    i64 l1 = (l[platform] + (s1 * (step % H)) % H) % H;
    for (int next_platform : adj[platform]) {
      i64 s2 = s[next_platform];
      i64 l2 = (l[next_platform] + (s2 * (step % H)) % H) % H;
      // (l1 + k * s1) % H = (l2 + k * s2) % H
      // => k = (l1 - l2) / (s2 - s1)
      i64 k = solve_for_k(l1, l2, s1, s2, H);
      if (k < 0 || (l1 + k * s1) % H != (l2 + k * s2) % H) {
        continue;
      }

      i64 step2 = step + k + 1;
      if (step2 < dist[next_platform]) {
        q.erase({dist[next_platform], next_platform});
        dist[next_platform] = step2;
        q.insert({step2, next_platform});
      }
    }
  }

  if (dist[n-1] == INF) {
    cout << "-1" << endl;
  } else {
    cout << dist[n-1] << endl;
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
