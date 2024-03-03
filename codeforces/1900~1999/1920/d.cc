#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<pair<int,int>> ops;
  for (int i = 0; i < n; ++i) {
    int b = 0, x = 0;
    cin >> b >> x;
    ops.emplace_back(b, x);
  }
  vector<array<i64,3>> data = {{0, 0, 0}};
  constexpr i64 MAX_K = 1e18;
  for (auto& [b, x] : ops) {
    auto& [size, type, info] = data.back();
    if (b == 1) {
      data.push_back({size+1, 1, x});
      if (data.back()[0] > MAX_K) {
        break;
      }
    } else {
      if ((double) size * (x+1) > MAX_K) {
        break;
      }
      data.push_back({size * (x+1), 2, info});
    }
  }

  priority_queue<pair<i64,int>, vector<pair<i64,int>>, less<>> pq;
  for (int i = 0; i < q; ++i) {
    i64 k = 0;
    cin >> k;
    pq.push({k, i});
  }

  vector<int> ans(q);
  while (data.size() > 1) {
    auto [size, type, info] = data.back();
    //cout << "size=" << size << endl;
    data.pop_back();
    while (!pq.empty() && pq.top().first >= size) {
      auto [k, index] = pq.top();
      pq.pop();
      if (k % size == 0) {
        ans[index] = info;
      } else {
        pq.push({k % size, index});
      }
    }
  }

  for (int i = 0; i < (int)ans.size(); ++i) {
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
