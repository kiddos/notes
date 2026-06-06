#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int m = 0;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<int> char_count(26);
  for (char ch : s) {
    char_count[ch-'a']++;
  }

  vector<int> indices;
  for (int i = 0; i < m; ++i) {
    if (b[i] == 0) {
      indices.push_back(i);
    }
  }

  int c = 25;
  string ans(m, ' ');
  while (!indices.empty()) {
    while (c >= 0 && char_count[c] < (int)indices.size()) {
      c--;
    }
    if (c < 0) {
      break;
    }
    for (int idx : indices) {
      ans[idx] = c + 'a';
    }
    vector<int> sum(m);
    for (int j = 0; j < m; ++j) {
      if (ans[j] == ' ') {
        continue;
      }
      for (int i = 0; i < m; ++i) {
        if (ans[i] == ' ') {
          sum[i] += abs(i-j);
        }
      }
    }
    vector<int> next_indices;
    for (int i = 0; i < m; ++i) {
      if (sum[i] == b[i] && ans[i] == ' ') {
        next_indices.push_back(i);
      }
    }
    // cout << "sum= ";
    // for (int i = 0; i < m; ++i) {
    //   cout << sum[i] << " ";
    // }
    // cout << endl;
    // cout << "next indices= ";
    // for (int idx : next_indices) {
    //   cout << idx << " ";
    // }
    // cout << endl;
    c--;
    indices = std::move(next_indices);
  }
  cout << ans << endl;
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
