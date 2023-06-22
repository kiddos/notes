#include <bits/stdc++.h>

using namespace std;


vector<int> create_tree() {
  vector<int> parents(22, -1);
  parents[2] = parents[3] = 1;
  parents[4] = 2;
  parents[5] = parents[6] = parents[7] = 4;
  parents[8] = 5;
  parents[9] = 8;
  parents[10] = 9;
  parents[11] = 10;
  parents[12] = 11;
  parents[13] = 12;
  parents[14] = 7;
  parents[15] = 14;
  parents[16] = 15;
  parents[17] = 16;
  parents[18] = 17;
  parents[19] = 18;
  parents[20] = 19;
  parents[21] = 16;
  return parents;
}

void solve() {
  vector<int> parents = create_tree();
  int n = parents.size();
  int L = ceil(log2(n))+1;

  vector<vector<int>> adj(n);
  for (int node = 1; node < n; ++node) {
    int p = parents[node];
    if (p > 0) {
      adj[p].push_back(node);
    }
  }

  vector<vector<int>> p(n, vector<int>(L));
  p[1] = vector<int>(L, 1);

  vector<int> depths(n);
  function<void(int)> dfs = [&](int node) {
    for (int child : adj[node]) {
      depths[child] = depths[node] + 1;
      p[child][0] = node;
      for (int l = 1; l < L; ++l) {
        p[child][l] = p[p[child][l-1]][l-1];
      }
      dfs(child);
    }
  };

  dfs(1);

  auto get_lca = [&](int a, int b) {
    if (depths[a] > depths[b]) {
      swap(a, b);
    }

    int depth_diff = depths[b] - depths[a];
    for (int l = 0; l < L; ++l) if (depth_diff & (1<<l)) {
      b = p[b][l];
    }

    if (a == b) {
      return a;
    }

    for (int l = L-1; l >= 0; --l) {
      if (p[a][l] != p[b][l]) {
        a = p[a][l];
        b = p[b][l];
      }
    }

    return p[a][0];
  };


  assert(get_lca(2, 3) == 1);
  assert(get_lca(12, 18) == 4);
  assert(get_lca(20, 18) == 18);
  assert(get_lca(20, 21) == 16);
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
