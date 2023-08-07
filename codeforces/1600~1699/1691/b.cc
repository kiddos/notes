#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  map<int, vector<int>> indices;
  for (int i = 1; i <= n; ++i) {
    int s = 0;
    cin >> s;
    indices[s].push_back(i);
  }

  vector<int> ans(n+1);
  for (auto& [s, index] : indices) {
    if (index.size() <= 1) {
      cout << "-1" << endl;
      return;
    }

    for (int j = 1; j < index.size(); ++j) {
      ans[index[j-1]] = index[j];
    }
    ans[index.back()] = index[0];
  }

  for (int i = 1; i <= n; ++i) {
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
