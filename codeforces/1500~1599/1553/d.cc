#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  vector<vector<int>> indices(26);
  for (int i = 0; i < (int)s.length(); ++i) {
    indices[s[i]-'a'].push_back(i);
  }

  int idx = s.length();
  for (int i = t.length()-1; i >= 0; --i) {
    int c = t[i]-'a';
    vector<int>& index = indices[c];
    auto it = upper_bound(index.begin(), index.end(), idx-1);
    if (it == index.begin()) {
      cout << "NO" << endl;
      return;
    }
    it--;
    while ((idx - *it - 1) % 2 == 1) {
      if (it == index.begin()) {
        cout << "NO" << endl;
        return;
      }
      it--;
    }

    idx = *it;
    // cout << "idx=" << idx << endl;
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
