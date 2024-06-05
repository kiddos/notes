#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_BIT = 30;

struct TrieNode {
  TrieNode* children[2];
  int count;

  TrieNode() : children{nullptr}, count(0) {}
  ~TrieNode() {
    for (int i = 0; i < 2; ++i) delete children[i];
  }
};

void insert(TrieNode* root, int x) {
  TrieNode* it = root;
  for (int i = MAX_BIT; i >= 0; --i) {
    int b = (x & (1<<i)) ? 1 : 0;
    if (!it->children[b]) it->children[b] = new TrieNode();
    it = it->children[b];
    it->count++;
  }
}

TrieNode* remove(TrieNode* node, int i, int x) {
  if (!node) {
    return nullptr;
  }

  int b = (x & (1<<i)) ? 1 : 0;
  node->children[b] = remove(node->children[b], i-1, x);
  if (--node->count == 0) {
    delete node;
    return nullptr;
  }
  return node;
}

int search(TrieNode *node, int i, int q, int x) {
  if (!node) {
    return x;
  }
  int b = (q & (1 << i)) ? 0 : 1;
  if (node->children[b]) {
    return search(node->children[b], i - 1, q, x | (b << i));
  }
  return search(node->children[1 - b], i - 1, q, x | ((1 - b) << i));
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0, w = 0;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  unique_ptr<TrieNode> even_root(new TrieNode());
  unique_ptr<TrieNode> odd_root(new TrieNode());
  vector<int> xors(n+1);
  vector<int> depths(n+1);
  vector<int> group_count(2);
  function<void(int, int)> dfs = [&](int node, int p) {
    if (depths[node] % 2 == 0) {
      insert(even_root.get(), xors[node]);
    } else {
      insert(odd_root.get(), xors[node]);
    }
    group_count[depths[node] % 2]++;

    for (auto [next_node, w] : adj[node])
      if (next_node != p) {
        xors[next_node] = xors[node] ^ w;
        depths[next_node] = depths[node] + 1;
        dfs(next_node, node);
      }
  };
  dfs(1, -1);

  int ax = 0;
  for (int i = 0; i < m; ++i) {
    char type = '\0';
    cin >> type;
    if (type == '^') {
      int y = 0;
      cin >> y;
      ax ^= y;
    } else if (type == '?') {
      int v = 0, x = 0;
      cin >> v >> x;

      int result1 = 0, result2 = 0;
      if (depths[v] % 2 == 0) {
        if (group_count[0] == 1) {
          int ans = search(odd_root.get(), MAX_BIT, xors[v] ^ x ^ ax, 0) ^ xors[v] ^ x ^ ax;
          cout << ans << " ";
        } else {
          remove(even_root.get(), MAX_BIT, xors[v]);
          result1 = search(even_root.get(), MAX_BIT, xors[v] ^ x, 0);
          result2 = search(odd_root.get(), MAX_BIT, xors[v] ^ x ^ ax, 0);
          insert(even_root.get(), xors[v]);
          int ans = max(result1 ^ xors[v] ^ x, result2 ^ xors[v] ^ x ^ ax);
          cout << ans << " ";
        }
      } else {
        if (group_count[1] == 1) {
          int ans = search(even_root.get(), MAX_BIT, xors[v] ^ x ^ ax, 0) ^ xors[v] ^ x ^ ax;
          cout << ans << " ";
        } else {
          remove(odd_root.get(), MAX_BIT, xors[v]);
          result1 = search(odd_root.get(), MAX_BIT, xors[v] ^ x, 0);
          result2 = search(even_root.get(), MAX_BIT, xors[v] ^ x ^ ax, 0);
          insert(odd_root.get(), xors[v]);
          // cout << "result1=" << result1 << ", result2=" << result2 << endl;
          int ans = max(result1 ^ xors[v] ^ x, result2 ^ xors[v] ^ x ^ ax);
          cout << ans << " ";
        }
      }
    }
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
