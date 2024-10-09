#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, p = 0, M = 0, m = 0;
  cin >> n >> p >> M >> m;

  // 2-sat problem
  int vars = p*2+(M+1)*2;
  vector<vector<int>> adj(vars+1);
  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    // x or y
    // !x -> y
    adj[x*2-1].push_back(y*2);
    // !y -> x
    adj[y*2-1].push_back(x*2);
  }

  vector<int> l(p+1), r(p+1);
  for (int i = 1; i <= p; ++i) {
    cin >> l[i] >> r[i];
  }

  for (int i = 1; i <= p; ++i) {
    int v1 = l[i] * 2 + p * 2;
    int v2 = (r[i]+1) * 2 + p * 2;
    // f >= l[i] or not i
    // f <= r[i] or not i
    // => !(f >= r[i]+1) or not i
    //
    // => v1 or not i
    // => !v2 or not i
    // !v1 -> not i
    adj[v1-1].push_back(i*2-1);
    // i -> v1
    adj[i*2].push_back(v1);
    // v2 -> not i
    adj[v2].push_back(i*2-1);
    // i -> v2
    adj[i*2].push_back(v2-1);
  }

  for (int f = 1; f < M; ++f) {
    int v1 = f*2 + p * 2;
    int v2 = (f+1) * 2 + p * 2;
    // v1 or not v2
    // !v1 -> !v2
    adj[v1-1].push_back(v2-1);
    // v2 -> v1
    adj[v2].push_back(v1);
  }

  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    // u ^ v
    // u -> -v
    adj[u*2].push_back(v*2-1);
    // v -> -u
    adj[v*2].push_back(u*2-1);
  }


  vector<int> ordering;
  vector<bool> visited(vars+1);
  function<void(int)> dfs1 = [&](int node) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      dfs1(next_node);
    }
    ordering.push_back(node);
  };

  for (int node = 1; node <= vars; ++node) {
    if (!visited[node]) {
      dfs1(node);
    }
  }

  vector<vector<int>> rev_adj(vars+1);
  for (int node = 1; node <= vars; ++node) {
    for (int next_node : adj[node]) {
      rev_adj[next_node].push_back(node);
    }
  }

  vector<int> components(vars+1, -1);
  function<void(int,int)> dfs2 = [&](int node, int c) {
    if (components[node] >= 0) {
      return;
    }
    components[node] = c;
    for (int next_node : rev_adj[node]) {
      dfs2(next_node, c);
    }
  };

  int c = 1;
  reverse(ordering.begin(), ordering.end());
  for (int node : ordering) {
    dfs2(node, c++);
  }

  vector<bool> solution(vars+1);
  for (int node = 2; node <= vars; node += 2) {
    int not_node = node - 1;
    if (components[node] == components[not_node]) {
      cout << "-1" << endl;
      return;
    }

    solution[node] = components[node] > components[not_node];
  }

  // for (int v = 1; v <= vars; ++v) {
  //   cout << solution[v] << " ";
  // }
  // cout << endl;

  vector<int> ans;
  for (int node = 2; node <= p * 2; node += 2) {
    if (solution[node]) {
      ans.push_back(node / 2);
    }
  }

  int f = 0;
  for (int node = 2 * p + 2; node <= vars; ++node) {
    if (solution[node]) {
      f = max(f, (node - p * 2) / 2);
    }
  }

  cout << ans.size() << " " << f << endl;
  for (int idx : ans) {
    cout << idx << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
