#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  vector<vector<int>> group(k);
  for (int i = 0; i < n; ++i) {
    group[i%k].push_back(p[i]);
  }
  for (int i = 0; i < k; ++i) {
    sort(group[i].begin(), group[i].end());
  }
  int incorrect = 0;
  for (int i = 0; i < k; ++i) {
    int mod = (i+1) % k;
    for (int j = 0; j < group[i].size(); ++j) {
      incorrect += group[i][j] % k != mod;
    }
  }

  if (incorrect == 0) {
    cout << "0" << endl;
  } else if (incorrect == 2) {
    cout << "1" << endl;
  } else {
    cout << "-1" << endl;
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
