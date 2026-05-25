#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> mapping(26);
  vector<int> index(26);
  iota(mapping.begin(), mapping.end(), 0);
  iota(index.begin(), index.end(), 0);

  for (int i = 0; i < m; ++i) {
    string x, y;
    cin >> x >> y;
    int c1 = x[0] - 'a', c2 = y[0] - 'a';
    int i1 = index[c1], i2 = index[c2];
    swap(mapping[i1], mapping[i2]);
    swap(index[c1], index[c2]);
    // for (int c = 0; c < 26; ++c) {
    //   cout << mapping[c] << " ";
    // }
    // cout << endl;
  }
  string ans;
  for (char ch : s) {
    int c = mapping[ch-'a'];
    ans.push_back(c + 'a');
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
