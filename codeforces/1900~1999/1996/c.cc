#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string a, b;
  cin >> a >> b;

  vector<vector<int>> pa(26, vector<int>(n+1));
  vector<vector<int>> pb(26, vector<int>(n+1));
  for (int i = 0; i < n; ++i) {
    pa[a[i]-'a'][i+1]++;
    pb[b[i]-'a'][i+1]++;
  }

  for (int c = 0; c < 26; ++c) {
    for (int i = 1; i <= n; ++i) {
      pa[c][i] += pa[c][i-1];
      pb[c][i] += pb[c][i-1];
    }
  }

  auto range_query = [&](vector<vector<int>>& p, int l, int r) -> vector<int> {
    vector<int> counts(26);
    for (int c = 0; c < 26; ++c) {
      counts[c] = p[c][r] - p[c][l-1];
    }
    return counts;
  };

  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;

    int ans = 0;
    vector<int> ca = range_query(pa, l, r);
    vector<int> cb = range_query(pb, l, r);
    for (int c = 0; c < 26; ++c) {
      if (ca[c] < cb[c]) {
        ans += cb[c] - ca[c];
      }
    }
    cout << ans << endl;
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
