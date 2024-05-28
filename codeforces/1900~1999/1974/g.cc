#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int m = 0, x = 0;
  cin >> m >> x;
  vector<int> c(m);
  for (int i = 0; i < m; ++i) cin >> c[i];

  priority_queue<int, vector<int>, less<>> pq;
  int total = 0;
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    if (c[i] <= total) {
      total -= c[i];
      pq.push(c[i]);
      ans++;
    } else {
      if (!pq.empty() && pq.top() > c[i]) {
        total += pq.top();
        total -= c[i];
        pq.pop();
        pq.push(c[i]);
      }
    }

    total += x;
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
