#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, m = 0;
  ll h = 0;
  cin >> n >> m >> h;

  vector<int> t(m);
  vector<array<ll, 3>> solves;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> t[j];
    sort(t.begin(), t.end());

    ll penalty = 0;
    int solved = 0;
    ll time = 0;
    for (int j = 0; j < m; ++j) {
      time += t[j];
      if (time > h) break;
      penalty += time;
      solved++;
    }
    solves.push_back({solved, -penalty, -i});
  }

  vector<int> index(n);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(), [&](int i1, int i2) {
    return solves[i1] > solves[i2];
  });

  int ans = find(index.begin(), index.end(), 0) - index.begin() + 1;
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
