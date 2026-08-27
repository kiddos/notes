#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 111111
// 100000
// 101110
// 101010
//
//
// 000011111
// 011101111
// 010101111
// 010101000
// 010101010
//
// ((number of indices where s[i] == s[i-1]) + 1) / 2 ?

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<int> l(q), r(q), k(q);
  for (int i = 0; i < q; ++i) {
    cin >> l[i] >> r[i] >> k[i];
    r[i]--;
    l[i]--;
  }

  vector<int> same(n);
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      same[i] = 1;
    }
  }

  vector<int> p_same = same;
  for (int i = 1; i < n; ++i) {
    p_same[i] += p_same[i-1];
  }

  vector<bool> ans;
  for (int i = 0; i < q; ++i) {
    int same_count = p_same[r[i]] - p_same[l[i]];
    ans.push_back((same_count+1) / 2 <= k[i]);
  }

  for (int i = 0; i < q; ++i) {
    if (ans[i]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
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
