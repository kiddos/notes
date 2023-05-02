#include <bits/stdc++.h>

using namespace std;

void solve() {
  int m = 0;
  cin >> m;
  vector<vector<int>> a(m);

  for (int i = 0; i < m; ++i) {
    int n = 0;
    cin >> n;
    for (int j = 0; j < n; ++j) {
      int p = 0;
      cin >> p;
      a[i].push_back(p);
    }
  }

  unordered_map<int, int> appear;
  for (int i = 0; i < m; ++i) {
    for (int p : a[i]) {
      appear[p]++;
    }
  }

  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    for (int p : a[i]) {
      if (--appear[p] == 0) appear.erase(p);
    }

    bool found = false;
    for (int p : a[i]) {
      if (!appear.count(p)) {
        ans.push_back(p);
        found = true;
        break;
      }
    }

    if (!found) {
      cout << "-1" << endl;
      return;
    }
  }

  for (int w : ans) cout << w << " ";
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
