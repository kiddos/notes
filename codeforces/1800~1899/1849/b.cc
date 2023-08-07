#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<pair<i64,int>> a;
  for (int i = 0; i < n; ++i) {
    i64 h = 0;
    cin >> h;
    a.push_back({h % k == 0 ? k : (h % k), i});
  }

  sort(a.begin(), a.end(), [&](auto& m1, auto& m2) {
    if (m1.first == m2.first) {
      return m1.second < m2.second;
    }
    return m1.first > m2.first;
  });

  for (int i = 0; i < n; ++i) {
    cout << a[i].second+1 << " ";
  }
  cout << endl;
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
