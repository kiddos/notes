#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, p = 0;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<pair<int,int>> residents;
  for (int i = 0; i < n; ++i) {
    residents.emplace_back(b[i], a[i]);
  }
  sort(residents.begin(), residents.end());
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  pq.push({p, n});

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [cost, left] = pq.top();
    pq.pop();

    ans += cost;

    if (--left > 0) {
      pq.push({cost, left});
    }
    pq.push(residents[i]);
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
