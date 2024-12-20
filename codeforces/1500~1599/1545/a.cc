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
  vector<int> b = a;
  sort(b.begin(), b.end());
  map<int, vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    indices[b[i]].push_back(i);
  }
  map<int, vector<vector<int>>> parity;
  for (auto& [val, index] : indices) {
    vector<vector<int>> p(2);
    for (int idx : index) {
      p[idx%2].push_back(idx);
    }
    parity[val] = p;
  }

  for (int i = 0; i < n; ++i) {
    vector<vector<int>>& p = parity[a[i]];
    if (p[i%2].empty()) {
      cout << "NO" << endl;
      return;
    }
    p[i%2].pop_back();
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
