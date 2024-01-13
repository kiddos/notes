#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Node {
  int x, l, r;
  bool deleted;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<Node> nodes;
  for (int i = 0; i < n; ++i) {
    nodes.push_back(Node{a[i], i-1, i+1, false});
  }

  auto should_remove = [&](int i) -> bool {
    if (i < 0 || i >= n) return false;

    int l = nodes[i].l;
    int r = nodes[i].r;
    int x = nodes[i].x;
    return (l >= 0 && nodes[l].x == x-1) || (r < n && nodes[r].x == x-1);
  };

  priority_queue<array<int,2>, vector<array<int,2>>, less<>> pq;
  for (int i = 0; i < n; ++i) {
    if (should_remove(i)) {
      pq.push({nodes[i].x, i});
    }
  }

  while (!pq.empty()) {
    auto [_, idx] = pq.top();
    pq.pop();

    if (nodes[idx].deleted) {
      continue;
    }

    nodes[idx].deleted = true;
    int l = nodes[idx].l;
    int r = nodes[idx].r;
    if (l >= 0) nodes[l].r = r;
    if (r < n) nodes[r].l = l;

    if (should_remove(l)) {
      pq.push({nodes[l].x, l});
    }
    if (should_remove(r))  {
      pq.push({nodes[r].x, r});
    }
  }

  int min_val = numeric_limits<int>::max();
  int left = 0;
  for (int i = 0; i < n; ++i) if (!nodes[i].deleted) {
    min_val = min(min_val, nodes[i].x);
    left += 1;
  }

  if (left == 1 && min_val == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
