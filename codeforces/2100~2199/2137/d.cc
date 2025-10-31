#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  map<int,vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    indices[b[i]].push_back(i);
  }

  vector<int> ans(n);
  int x = 0;
  for (auto [c, idx] : indices) {
    if (idx.size() % c != 0) {
      cout << "-1" << endl;
      return;
    }
    for (int j = 0; j < (int)idx.size(); ++j) {
      if (j % c == 0) {
        x++;
      }
      ans[idx[j]] = x;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
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
