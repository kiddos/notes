#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
enum class UpdateType { Assign, Add };
 
template <typename T, typename F, T DEFAULT, UpdateType UPDATE_TYPE>
class GenericSegmentTree {
 public:
  GenericSegmentTree(int n) : n(n), data_(n * 4) {}
 
  T query(int l, int r) noexcept {
    T ans = DEFAULT;
    l += n;
    r += n;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        ans = merge(ans, data_[l++]);
      }
      if (r & 1) {
        ans = merge(ans, data_[--r]);
      }
    }
    return ans;
  }
 
  void update(int index, const T& val) noexcept {
    index += n;
    data_[index] = val;
    for (; index > 1; index >>= 1) {
      data_[index / 2] = merge(data_[index], data_[index ^ 1]);
    }
  }
 
 private:
  int n;
  vector<T> data_;
  F merge;
};
 
template <typename T>
struct MaxFunctor {
  T operator()(T a, T b) const { return std::max(a, b); }
};
 
using MaxSegmentTree = GenericSegmentTree<int, MaxFunctor<int>, 0, UpdateType::Assign>;
 
void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> v(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
 
  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
 
  vector<int> parent(n+1);
  vector<int> node_count(n+1, 1);
  vector<int> heavy(n+1, -1);
  vector<int> depth(n+1);
  auto dfs = [&](const auto& self, int node, int p) -> void {
    int largest = 0;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      parent[next_node] = node;
      depth[next_node] = depth[node] + 1;
      self(self, next_node, node);
      node_count[node] += node_count[next_node];
 
      if (node_count[next_node] > largest) {
        largest = node_count[next_node];
        heavy[node] = next_node;
      }
    }
  };
 
  dfs(dfs, 1, 1);
 
  vector<int> head(n+1);
  vector<int> position(n+1);
  int current_position = 0;
  auto decompose = [&](const auto& self, int node, int h) -> void {
    head[node] = h;
    position[node] = current_position++;
    if (heavy[node] != -1) {
      self(self, heavy[node], h);
    }
    for (int next_node : adj[node]) {
      if (next_node != parent[node] && next_node != heavy[node]) {
        self(self, next_node, next_node);
      }
    }
  };
 
  decompose(decompose, 1, 1);
 
  MaxSegmentTree tree(current_position);
  for (int i = 1; i <= n; ++i) {
    tree.update(position[i],  v[i]);
  }
 
  auto update = [&](int node, int val) -> void {
    tree.update(position[node], val);
  };
 
  auto query_range = [&](int p1, int p2) -> int {
    return tree.query(min(p1, p2), max(p1, p2) + 1);
  };
 
  auto query = [&](int a, int b) -> int {
    int ans = 0;
    for (;head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]]) {
        swap(a, b);
      }
      ans = max(ans, query_range(position[head[b]], position[b]));
    }
    if (depth[a] > depth[b]) {
      swap(a, b);
    }
    ans = max(ans, query_range(position[a], position[b]));
    return ans;
  };
 
  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int s = 0, x = 0;
      cin >> s >> x;
      update(s, x);
    } else if (type == 2) {
      int a = 0, b = 0;
      cin >> a >> b;
      cout << query(a, b) << " ";
    }
  }
  cout << endl;
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  solve();
  return 0;
}
