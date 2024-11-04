#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  priority_queue<pair<i64,int>, vector<pair<i64,int>>, greater<>> pq;
  pq.push({0, 1});
  vector<i64> skips(n+1, numeric_limits<i64>::max());
  skips[1] = 0;

  while (!pq.empty()) {
    auto [skipped, node] = pq.top();
    pq.pop();

    if (b[node] > node) {
      i64 new_skipped = skipped + a[node];
      if (new_skipped < skips[b[node]]) {
        skips[b[node]] = new_skipped;
        pq.push({new_skipped, b[node]});
      }
    }
    if (node-1 > 0 && skipped < skips[node-1]) {
      skips[node-1] = skipped;
      pq.push({skipped, node-1});
    }
  }

  // for (int node = 1; node <= n; ++node) {
  //   cout << skips[node] << " ";
  // }
  // cout << endl;

  i64 prefix = 0;
  i64 ans = 0;
  for (int node = 1; node <= n; ++node) {
    if (skips[node] < numeric_limits<i64>::max()) {
      prefix += a[node];
      i64 score = prefix - skips[node];
      ans = max(ans, score);
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
