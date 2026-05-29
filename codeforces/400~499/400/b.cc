#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<int> dists;
  for (int i = 0; i < n; ++i) {
    int G = -1, S = -1;
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'G') {
        G = j;
      } else if (s[i][j] == 'S') {
        S = j;
      }
    }
    if (S < G)  {
      cout << "-1" << endl;
      return;
    }
    dists.push_back(S - G);
  }
  sort(dists.begin(), dists.end());
  dists.resize(unique(dists.begin(), dists.end()) - dists.begin());
  int ans = dists.size();
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
