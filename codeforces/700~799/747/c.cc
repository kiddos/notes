#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  priority_queue<int, vector<int>, greater<>> servers;
  for (int s = 1; s <= n; ++s) {
    servers.push(s);
  }
  vector<int> t(q), k(q), d(q);
  for (int i = 0; i < q; ++i) {
    cin >> t[i] >> k[i] >> d[i];
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> done;
  vector<int> ans(q, -1);
  for (int i = 0; i < q; ++i) {
    while (!done.empty() && done.top().first < t[i]) {
      auto [td, server] = done.top();
      done.pop();
      servers.push(server);
    }
    if ((int)servers.size() >= k[i]) {
      int sum = 0;
      for (int j = 0; j < k[i]; ++j) {
        int server = servers.top();
        servers.pop();
        sum += server;
        done.push({t[i] + d[i] - 1, server});
      }
      ans[i] = sum;
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
