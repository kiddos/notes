#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0, d = 0, w = 0;
  cin >> n >> k >> d >> w;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) cin >> t[i];

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    while (!pq.empty() && pq.top().first + d < t[i]) {
      pq.pop();
    }
    if (pq.empty()) {
      if (k > 1) {
        pq.push({t[i]+w, k-1});
      }
      ans++;
    } else {
      auto p = pq.top();
      pq.pop();
      p.second--;
      if (p.second > 0) {
        pq.push(p);
      }
    }
  }
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
