#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  priority_queue<pair<int,int>, vector<pair<int,int>>, less<>> pq;
  for (int i = 1; i <= n; ++i) {
    pq.push({a[i], i});
  }

  vector<pair<int,int>> ans;
  while (pq.size() >= 2) {
    auto [a1, i1] = pq.top();
    pq.pop();
    auto [a2, i2] = pq.top();
    pq.pop();
    if (a1 == 0 || a2 == 0) {
      break;
    }
    ans.push_back({i1, i2});
    pq.push({a1-1, i1});
    pq.push({a2-1, i2});
  }

  cout << ans.size() << endl;
  for (auto& [i1, i2] : ans) {
    cout << i1 << " " << i2 << endl;
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
