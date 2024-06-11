#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) cin >> c[i];
  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int total = accumulate(c.begin()+1, c.end(), 0);

  vector<int> children(n+1);
  vector<int> parents(n+1);

  function<void(int,int)> dfs = [&](int node, int p) {
    parents[node] = p;

    int b = 0;
    for (int next_node : adj[node]) if (next_node != p) {
      b += c[next_node];

      dfs(next_node, node);
    }
    children[node] = b;
  };

  dfs(1, 0);

  vector<int> counts(4);
  int white_parents = 0;
  for (int node = 1; node <= n; ++node) {
    if (c[node] == 1) {
      counts[min(children[node], 3)]++;

      if (c[parents[node]] == 0) {
        white_parents++;
      }
    }
  }
  int two_children_black = 0;
  for (int node = 1; node <= n; ++node) {
    if (c[node] == 1 && children[node] == 2) {
      two_children_black ^= node;
    }
  }

  while (q-- > 0) {
    int u = 0;
    cin >> u;
    int parent = parents[u];

    if (c[u] == 1) {
      // black to white
      if (c[parent] == 1 && children[parent] == 2) {
        two_children_black ^= parent;
      }
      children[parent]--;
      if (c[parent] == 1 && children[parent] == 2) {
        two_children_black ^= parent;
      }

      if (c[parent] == 1) {
        counts[min(children[parent], 3)]++;
        counts[min(children[parent]+1, 3)]--;
      } else {
        white_parents--;
      }

      white_parents += children[u];
      if (children[u] == 2) {
        two_children_black ^= u;
      }

      counts[min(children[u], 3)]--;

      c[u] = 0;
      total--;
    } else {
      // white to black
      if (c[parent] == 1 && children[parent] == 2) {
        two_children_black ^= parent;
      }
      children[parent]++;
      if (c[parent] == 1 && children[parent] == 2) {
        two_children_black ^= parent;
      }

      if (c[parent] == 1) {
        counts[min(children[parent], 3)]++;
        counts[min(children[parent]-1, 3)]--;
      } else {
        white_parents++;
      }

      counts[min(children[u], 3)]++;

      if (children[u] == 2) {
        two_children_black ^= u;
      }

      white_parents -= children[u];

      c[u] = 1;
      total++;
    }

    // for (int c = 0; c < 2; ++c) {
    //   cout << "parent=" << c << endl;
    //   for (int node = 1; node <= n; ++node) {
    //     cout << children[c][node] << " ";
    //   }
    //   cout << endl;
    // }
    //
    // cout << "black counts: " << endl;
    // for (int c = 0; c < 4; ++c) {
    //   cout << counts[c] << " ";
    // }
    // cout << endl;
    // cout << "white parents=" << white_parents << endl;
    // cout << "two children black=" << two_children_black << endl;

    if (total == 0) {
      cout << "NO" << endl;
      continue;
    }

    // there should be no children[1][u] >= 3
    if (counts[3] > 0) {
      // cout << "count[3] > 0" << endl;
      cout << "NO" << endl;
      continue;
    }

    // there should be at most 1 children[1][u] == 2
    if (counts[2] > 1) {
      // cout << "count[2] > 1" << endl;
      cout << "NO" << endl;
      continue;
    }

    // there should only be at most 1 black node with 1 white parent
    if (white_parents > 1) {
      cout << "NO" << endl;
      continue;
    }

    // if there is a node with children[1][u] == 2
    // its parent must be white
    if (counts[2] == 1 && c[parents[two_children_black]] != 0) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
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
