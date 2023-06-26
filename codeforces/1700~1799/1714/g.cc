#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Edge {
  int node;
  ll a, b;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<Edge>> adj(n+1);

  for (int j = 2; j <= n; ++j) {
    int p = 0;
    ll a = 0, b = 0;
    cin >> p >> a >> b;
    adj[p].push_back(Edge{j, a, b});
  }

  vector<int> r(n+1);
  vector<ll> Bs;
  function<void(int,ll,ll,int)> dfs = [&](int node, ll A, ll B, int len) {
    r[node] = upper_bound(Bs.begin(), Bs.end(), A) - Bs.begin();
    for (auto& [next_node, a, b] : adj[node]) {
      Bs.push_back(B+b);
      dfs(next_node, A + a, B + b, len+1);
      Bs.pop_back();
    }
  };

  dfs(1, 0, 0, 0);

  for (int i = 2; i <= n; ++i) {
    cout << r[i] << " ";
  }
  cout << endl;
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
