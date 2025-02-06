#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, x = 0;
  cin >> n >> m >> x;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(h[i], i);
  }
  sort(p.rbegin(), p.rend());
  vector<vector<int>> indices(m);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  for (int i = 0; i < m; ++i) {
    pq.push({0, i});
  }
  for (int i = 0; i < n; ++i) {
    auto [height, idx] = p[i];
    auto [y, tower_index] = pq.top();
    pq.pop();
    indices[tower_index].push_back(idx);
    y += height;
    pq.push({y, tower_index});
  }

  vector<int> ans(n);
  vector<i64> total(m);
  for (int i = 0; i < m; ++i) {
    for (int idx : indices[i]) {
      total[i] += h[idx];
      ans[idx] = i+1;
    }
  }
  sort(total.begin(), total.end());
  if (total.back() - total[0] > x) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
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
