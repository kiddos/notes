#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({a[i], i%2});
  }
  sort(p.begin(), p.end());
  for (int i = 1; i < n; ++i) {
    int c1 = p[i-1].second;
    int c2 = p[i].second;
    if (c1 == c2) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
