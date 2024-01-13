#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class SegmentTree {
 public:
  SegmentTree(int n) : data_(n * 4), lazy_(n * 4) {}

  void update(int i, int tl, int tr, int l, int r, int x) {
    if (tr < l || tl > r) {
      return;
    }

    if (tl >= l && tr <= r) {
      data_[i] += x;
      lazy_[i] += x;
      return;
    }

    push(i, tl, tr);
    int tm = tl + (tr - tl) / 2;
    if (l <= tm) update(i*2+1, tl, tm, l, r, x);
    if (r > tm) update(i*2+2, tm+1, tr, l, r, x);
    data_[i] = max(data_[i*2+1], data_[i*2+2]);
  }

  int query_max(int i, int tl, int tr, int ql, int qr) {
    if (tr < ql || tl > qr) {
      return 0;
    }

    if (tl >= ql && tr <= qr) {
      return data_[i];
    }

    push(i, tl, tr);

    int tm = tl + (tr - tl) / 2;
    return max(query_max(i*2+1, tl, tm, ql, min(qr, tm)),
               query_max(i*2+2, tm+1, tr, max(ql, tm+1), qr));
  }

 private:
  vector<int> data_, lazy_;

  void push(int i, int tl, int tr) {
    if (lazy_[i]) {
      if (tl != tr) {
        data_[i*2+1] += lazy_[i];
        lazy_[i*2+1] += lazy_[i];

        data_[i*2+2] += lazy_[i];
        lazy_[i*2+2] += lazy_[i];
      }
      lazy_[i] = 0;
    }
  }
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 2; i <= n; ++i) cin >> p[i];
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[p[i]].push_back(i);
  }

  vector<int> t_in(n+1), t_out(n+1);
  int t = 0;
  function<void(int)> dfs1 = [&](int node) {
    t_in[node] = ++t;
    for (int child : adj[node]) {
      dfs1(child);
    }
    t_out[node] = t;
  };
  
  dfs1(1);

  vector<set<pair<int,int>>> color_group(n+1);
  SegmentTree tree(t+1);
  i64 ans = 1;
  function<void(int)> dfs2 = [&](int node) {
    for (int child : adj[node]) {
      dfs2(child);
    }

    set<pair<int,int>>& s = color_group[a[node]];
    for (auto it = s.lower_bound({t_in[node], node}); it != s.upper_bound({t_out[node]+1, node}); ) {
      auto it2 = next(it);
      auto item = *it;
      int node2 = item.second;
      tree.update(0, 0, t, t_in[node2], t_out[node2], -1);
      s.erase(it);
      it = it2;
    }
    color_group[a[node]].insert({t_in[node], node});
    tree.update(0, 0, t, t_in[node], t_out[node], 1);
    
    i64 temp = 1;
    for (int child : adj[node]) {
      i64 result = tree.query_max(0, 0, t, t_in[child], t_out[child]);
      //cout << "child=" << child << " (" << t_in[child] << "-" << t_out[child] << ")"
        //<< ", query=" << result << ", ans=" << result * temp << endl; 
      ans = max(ans, result * temp);
      temp = max(temp, result);
    }
  };

  dfs2(1);

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
