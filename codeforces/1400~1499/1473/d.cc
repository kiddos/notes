#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;
  s = " " + s;
  vector<int> xs = {0};
  for (int i = 1, x = 0; i <= n; ++i) {
    if (s[i] == '+') {
      x++;
    } else if (s[i] == '-') {
      x--;
    }
    xs.push_back(x);
  }

  vector<int> suffix_min(n+2), suffix_max(n+2);
  suffix_min.back() = suffix_max.back() = xs.back();
  for (int i = n; i >= 0; --i) {
    suffix_min[i] = min(xs[i], suffix_min[i+1]);
    suffix_max[i] = max(xs[i], suffix_max[i+1]);
  }

  vector<int> prefix_min(n+1), prefix_max(n+1);
  for (int i = 1; i <= n; ++i) {
    prefix_min[i] = min(xs[i], prefix_min[i-1]);
    prefix_max[i] = max(xs[i], prefix_max[i-1]);
  }

  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;

    int max_inc = suffix_max[r+1] - xs[r];
    int max_dec = suffix_min[r+1] - xs[r];
    int last_x = xs[l-1];
    int max_x = max(last_x + max_inc, prefix_max[l-1]);
    int min_x = min(last_x + max_dec, prefix_min[l-1]);
    int range = max_x - min_x + 1;
    ans.push_back(range);
  }

  for (int i = 0; i < m; ++i) {
    cout << ans[i] << endl;
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
