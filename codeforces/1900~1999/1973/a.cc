#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> p(3);
  cin >> p[0] >> p[1] >> p[2];
  int sum = p[0] + p[1] + p[2];
  if (sum % 2 == 1) {
    cout << "-1" << endl;
    return;
  }

  priority_queue<int, vector<int>, less<>> pq;
  pq.push(p[0]);
  pq.push(p[1]);
  pq.push(p[2]);
  int ans = 0;
  while (!pq.empty() && pq.top() > 0) {
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    if (y == 0) {
      break;
    }
    ans++;
    pq.push(x-1);
    pq.push(y-1);
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
