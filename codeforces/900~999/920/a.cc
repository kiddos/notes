#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(k);
  for (int i = 0; i < k; ++i) {
    cin >> x[i];
  }
  vector<bool> visited(n+1);
  queue<int> q;
  for (int i = 0; i < k; ++i) {
    q.push(x[i]);
    visited[x[i]] = true;
  }

  int ans = 0;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int pos = q.front();
      q.pop();
      for (int next_pos : {pos-1, pos+1}) {
        if (next_pos < 1 || next_pos > n) {
          continue;
        }
        if (visited[next_pos]) {
          continue;
        }
        visited[next_pos] = true;
        q.push(next_pos);
      }
    }
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
