#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) p.push_back(p.back() + c[i]);
  vector<int> one = {0};
  for (int i = 0; i < n; ++i) one.push_back(one.back() + (c[i] == 1));

  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    r--;
    l--;
    if (l == r) {
      cout << "NO" << endl;
      continue;
    }

    int ones = one[r+1] - one[l];
    i64 sum = p[r+1] - p[l];
    i64 not_one_sum = sum - ones;
    i64 not_one_count = (r-l+1 - ones);
    if (not_one_sum - not_one_count >= ones) {
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
