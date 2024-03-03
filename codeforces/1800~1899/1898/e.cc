#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  vector<vector<int>> indices(26);
  for (int i = n-1; i >= 0; --i) {
    int c = s[i] - 'a';
    indices[c].push_back(i);
  }

  for (int i = 0; i < m; ++i) {
    int c = t[i] - 'a';

    if (indices[c].empty()) {
      cout << "NO" << endl;
      return;
    }

    int k = indices[c].back();
    indices[c].pop_back();

    for (int c2 = 0; c2 < c; ++c2) {
      while (!indices[c2].empty() && indices[c2].back() <= k) {
        indices[c2].pop_back();
      }
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
