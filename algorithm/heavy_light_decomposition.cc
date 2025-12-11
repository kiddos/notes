#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum class UpdateType { Assign, Add };

template <typename T, typename F, T DEFAULT, UpdateType UPDATE_TYPE>
class GenericSegmentTreeIterative {
 public:
  GenericSegmentTreeIterative(int n) : n(n), data_(n * 2) {}
 
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

using SegmentTree = GenericSegmentTreeIterative<int, MaxFunctor<int>, 0, UpdateType::Assign>;

template <typename T, typename F>
class HLD {
 public:
  HLD(vector<vector<int>>& adj, int root)
      : root_(root),
        parent_(adj.size()),
        node_count_(adj.size(), 1),
        heavy_(adj.size(), -1),
        depth_(adj.size()),
        adj_(adj),
        current_position_(0),
        head_(adj.size()),
        position_(adj.size()),
        tree_(0) {
    dfs(root, root);
    decompose(root, root);

    tree_ = T(current_position_);
  }

  void update(int node, int val) {
    tree_.update(position_[node], val);
  }

  T query_path(int a, int b) {
    T ans = 0;
    for (;head_[a] != head_[b]; b = parent_[head_[b]]) {
      if (depth_[head_[a]] > depth_[head_[b]]) {
        swap(a, b);
      }
      ans = max(ans, query_range(position_[head_[b]], position_[b]));
    }
    if (depth_[a] > depth_[b]) {
      swap(a, b);
    }
    ans = max(ans, query_range(position_[a], position_[b]));
    return ans;
  }

 private:
  int root_;
  vector<int> parent_;
  vector<int> node_count_;
  vector<int> heavy_;
  vector<int> depth_;
  vector<vector<int>> adj_;

  int current_position_;
  vector<int> head_;
  vector<int> position_;
  SegmentTree tree_;
  F merge_;

  void dfs(int node, int p) {
    int largest = 0;
    for (int next_node : adj_[node]) {
      if (next_node == p) {
        continue;
      }
      parent_[next_node] = node;
      depth_[next_node] = depth_[node] + 1;
      dfs(next_node, node);
      node_count_[node] += node_count_[next_node];

      if (node_count_[next_node] > largest) {
        largest = node_count_[next_node];
        heavy_[node] = next_node;
      }
    }
  }

  void decompose(int node, int h) {
    head_[node] = h;
    position_[node] = current_position_++;
    if (heavy_[node] != -1) {
      decompose(heavy_[node], h);
    }
    for (int next_node : adj_[node]) {
      if (next_node != parent_[node] && next_node != heavy_[node]) {
        decompose(next_node, next_node);
      }
    }
  }

  inline T query_range(int i1, int i2) {
    return tree_.query(min(i1, i2), max(i1, i2) + 1);
  }
};

void solve() {
  int n = 5;
  vector<vector<int>> adj(n+1);
  vector<pair<int,int>> edges;
  edges.push_back({1, 2});
  edges.push_back({1, 3});
  edges.push_back({2, 4});
  edges.push_back({2, 5});

  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> values = {0, 2, 4, 1, 3, 3};

  HLD<int, MaxFunctor<int>> hld(adj, 1);
  for (int i = 1; i <= n; ++i) {
    hld.update(i, values[i]);
  }

  assert(hld.query_path(3, 5) == 4);
  hld.update(2, 2);
  assert(hld.query_path(3, 5) == 3);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
