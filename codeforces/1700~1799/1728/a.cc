#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  priority_queue<pair<int,int>, vector<pair<int,int>>, less<>> pq;
  for (int i = 1; i <= n; ++i) {
    int count = 0;
    cin >> count;
    pq.push({count, i});
  }

  while (pq.size() > 1) {
    auto [a, i1] = pq.top();
    pq.pop();
    auto [b, i2] = pq.top();
    pq.pop();
    if (a > b) {
      pq.push({a-b, i1});
    }
  }

  int ans = pq.top().second;
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
