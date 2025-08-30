#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> k(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> k[i];
  }
  vector<i64> c(m+1);
  for (int i = 1; i <= m; ++i) {
    cin >> c[i];
  }

  vector<int> count(m+1);
  for (int i = 1; i <= n; ++i) {
    count[k[i]]++;
  }

  priority_queue<int, vector<int>, greater<>> pq;
  i64 dollars = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < count[i]; ++j) {
      pq.push(c[i]);
    }
    while ((int)pq.size() > i) {
      dollars += pq.top();
      pq.pop();
    }
  }
  vector<i64> p = c;
  for (int i = 1; i <= m; ++i) {
    p[i] += p[i-1];
  }

  i64 ans = dollars + p[pq.size()];
  while (pq.size() > 0) {
    dollars += pq.top();
    pq.pop();

    i64 total = dollars + p[pq.size()];
    ans = min(ans, total);
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
