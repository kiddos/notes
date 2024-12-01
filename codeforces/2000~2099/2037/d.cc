#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  i64 L = 0;
  cin >> n >> m >> L;
  deque<pair<int,int>> hurdle;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    hurdle.emplace_back(l, r);
  }
  deque<pair<int,int>> powerups;
  for (int i = 0; i < m; ++i) {
    int x = 0, v = 0;
    cin >> x >> v;
    powerups.emplace_back(x, v);
  }

  int ans = 0;
  i64 k = 1;
  priority_queue<int,vector<int>, less<>> pq;
  for (auto [l, r] : hurdle) {
    while (!powerups.empty() && powerups.front().first < l) {
      pq.push(powerups.front().second);
      powerups.pop_front();
    }

    i64 require_power = r - l + 2;
    while (!pq.empty() && k < require_power) {
      k += pq.top();
      pq.pop();
      ans++;
    }
    if (k < require_power) {
      cout << "-1" << endl;
      return;
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
