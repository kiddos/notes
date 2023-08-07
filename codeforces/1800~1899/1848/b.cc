#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) cin >> c[i];

  vector<int> color_index(k+1);
  vector<vector<int>> dists(k+1);
  for (int i = 1; i <= n; ++i) {
    int d = i - color_index[c[i]];
    dists[c[i]].push_back(d);
    color_index[c[i]] = i;
  }
  for (int color = 1; color <= k; ++color) {
    dists[color].push_back(n+1 - color_index[color]);
  }

  int ans = numeric_limits<int>::max();
  for (int color = 1; color <= k; ++color) {
    vector<int>& dist = dists[color];
    priority_queue<int, vector<int>, less<>> pq;
    for (int d : dist) {
      pq.push(d);
    }
    int largest = pq.top();
    pq.pop();
    pq.push((largest+1) / 2);

    ans = min(ans, pq.top()-1);
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
