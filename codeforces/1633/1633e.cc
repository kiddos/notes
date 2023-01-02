#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct Edge {
  int u, v, w;
};

struct Result {
  LL cost;
  LL q;
};

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int Find(int x) {
    if (x != parent_[x]) {
      parent_[x] = Find(parent_[x]);
    }
    return parent_[x];
  }

  bool Union(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px == py) return false;
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
    return true;
  }

 private:
  vector<int> parent_, rank_;
};

Result kruskal(int n, vector<Edge>& edges, LL q) {
  DisjointSet ds(n);
  sort(edges.begin(), edges.end(), [&](auto& e1, auto& e2) {
    return abs(e1.w-q) < abs(e2.w-q);
  });

  Result result{0, 0};
  for (Edge& edge : edges) {
    int u = edge.u-1, v = edge.v-1, weight = edge.w;
    if (ds.Union(u, v)) {
      if (weight >= q) {
        result.cost += weight;
        result.q--;
      } else {
        result.cost -= weight;
        result.q++;
      }
    }
  }
  return result;
}

LL solve(int n, vector<Edge>& edges, vector<LL>& queries, int k, LL a, LL b, LL c) {
  set<LL> w = {0};
  int m = edges.size();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      LL half = (edges[i].w + edges[j].w) / 2;
      w.insert(half);
      w.insert(half+1);
      if ((edges[i].w + edges[j].w) % 2 == 1) w.insert(half+2);
    }
  }
  vector<LL> weights(w.begin(), w.end());
  vector<Result> results;
  for (LL weight : weights) {
    results.push_back(kruskal(n, edges, weight));
  }

  LL ans = 0;
  LL q = 0;
  for (int i = 0; i < k; ++i) {
    if (i < queries.size()) q = queries[i];
    else q = (q * a + b) % c;

    int index = upper_bound(weights.begin(), weights.end(), q) - weights.begin() -1;
    LL cost = results[index].cost + (results[index].q * q);
    ans ^= cost;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0, m = 0;
  cin >> n >> m;
  vector<Edge> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }

  LL p = 0, k = 0, a = 0, b = 0, c = 0;
  cin >> p >> k >> a >> b >> c;
  vector<LL> queries(p);
  for (int i = 0; i < p; ++i) cin >> queries[i];

  LL ans = solve(n, edges, queries, k, a, b, c);
  cout << ans << endl;
  return 0;
}
