#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  i64 d = 0;
  cin >> n >> m >> d;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  priority_queue<i64, vector<i64>, greater<>> pq;
  i64 sum = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      sum += a[i];
      pq.push(a[i]);
    }
    while ((int)pq.size() > m) {
      sum -= pq.top();
      pq.pop();
    }

    i64 entertain = sum - (i+1) * d;
    ans = max(ans, entertain);
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
