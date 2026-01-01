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
  int g1 = 0;
  int g2 = -1;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[g1]) {
      g2 = i;
      break;
    }
  }
  if (g2 < 0) {
    cout << "NO" << endl;
    return;
  }

  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    if (i == g2) {
      continue;
    }
    if (a[i] == a[g1]) {
      edges.emplace_back(g2, i);
    } else {
      edges.emplace_back(g1, i);
    }
  }
  edges.emplace_back(g1, g2);

  cout << "YES" << endl;
  for (auto [u, v] : edges) {
    cout << u+1 << " " << v+1 << endl;
  }
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
