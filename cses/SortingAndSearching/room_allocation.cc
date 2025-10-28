#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,3>> interval;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    interval.push_back({a, b, i});
  }
  sort(interval.begin(), interval.end());

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  int room_id = 0;
  vector<int> ans(n);
  for (auto [a, b, idx] : interval) {
    if (pq.empty() || pq.top().first >= a) {
      pq.push({-1, ++room_id});
    }

    auto [depart_t, id] = pq.top();
    pq.pop();
    ans[idx] = id;
    pq.push({b, id});
  }

  cout << room_id << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
