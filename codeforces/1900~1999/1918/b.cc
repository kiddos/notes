#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 6
// 2 5 6 1 3 4
// 1 5 3 6 2 4

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(a[i], b[i]);
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; ++i) {
    cout << p[i].first << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << p[i].second << " ";
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
