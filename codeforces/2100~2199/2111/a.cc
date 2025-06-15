#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// [0, 0, 0]
// [1, 1, 0]
// [1, 1, 3]
// [3, 1, 3]
// [3, 4, 2]
void solve() {
  int x = 0;
  cin >> x;
  priority_queue<i64, vector<i64>, greater<>> pq;
  for (int i = 0; i < 3; ++i) {
    pq.push(0);
  }
  int ans = 0;
  while (pq.top() < x) {
    pq.top();
    pq.pop();
    i64 smallest = pq.top();
    pq.push(smallest * 2 + 1);
    ans++;
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
