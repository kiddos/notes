#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<vector<int>> ans(n, vector<int>(n));
  vector<pair<int,int>> seq;
  for (int i = 0; i < n; ++i) {
    seq.emplace_back(p[i], p[i]);
  }
  for (int offset = 0; offset < n; ++offset) {
    vector<pair<int,int>> seq2;

    int r = offset, c = 0, k = 0;
    while (r < n && c < n && k < (int)seq.size()) {
      ans[r][c] = seq[k].first;
      if (--seq[k].second > 0) {
        seq2.push_back(seq[k]);
      }
      r++;
      c++;
      k++;
    }
    seq = std::move(seq2);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (ans[i][j]) {
        cout << ans[i][j] << " ";
      }
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
