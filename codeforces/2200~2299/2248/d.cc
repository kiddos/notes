#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s, t;
  cin >> s >> t;
  vector<int> l(q), r(q);
  for (int i = 0; i < q; ++i) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }

  vector<int> same(n), diff(n);
  for (int i = 0; i < n; ++i) {
    int d1 = s[i]-'0';
    int d2 = t[i]-'0';
    same[i] = d1 == d2;
    diff[i] = d1 - d2;
  }

  vector<int> p_same = {0}, p_diff = {0};
  for (int i = 0; i < n; ++i) {
    p_same.push_back(p_same.back() + same[i]);
    p_diff.push_back(p_diff.back() + diff[i]);
  }

  auto process_query = [&](int l, int r) -> bool {
    int diff_count = abs(p_diff[r+1] - p_diff[l]);
    int same_count = p_same[r+1] - p_same[l];
    return diff_count <= same_count;
  };

  vector<bool> ans(q);
  for (int i = 0; i < q; ++i) {
    ans[i] = process_query(l[i], r[i]);
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
