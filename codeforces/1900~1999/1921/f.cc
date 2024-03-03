#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int sq = 1;
  while (sq*sq <= n) {
    sq++;
  }

  vector<vector<i64>> p1(sq+1, vector<i64>(n+1));
  vector<vector<i64>> p2(sq+1, vector<i64>(n+1));
  for (int d = 1; d <= sq; ++d) {
    for (int i = 1; i <= n; ++i) {
      p1[d][i] = (i >= d ? p1[d][i-d] : 0) + a[i] * ((i-1)/d + 1);
      p2[d][i] = (i >= d ? p2[d][i-d] : 0) + a[i];
    }
  }

  // cout << endl << "p1:" << endl;
  // for (int d = 1; d <= s; ++d) {
  //   for (int i = 0; i <= n; ++i) {
  //     cout << p1[d][i] << " ";
  //   }
  //   cout << endl;
  // }
  //
  // cout << "p2:" << endl;
  // for (int d = 1; d <= s; ++d) {
  //   for (int i = 0; i <= n; ++i) {
  //     cout << p2[d][i] << " ";
  //   }
  //   cout << endl;
  // }

  auto compute_query = [&](int s, int d, int k) -> i64 {
    if (d > sq) {
      i64 ans = 0;
      int to = s + d * (k-1);
      for (int i = s, j = 1; i <= to; i += d, ++j) {
        ans += a[i] * j;
      }
      return ans;
    }
    int l = s, r = s + d * (k-1);
    i64 sum1 = p1[d][r] - p1[d][max(l-d, 0)];
    i64 sum2 = p2[d][r] - (l >= d ? p2[d][l-d] : 0);
    // cout << "sum1=" << sum1 << ", sum2=" << sum2 << endl;
    return sum1 - sum2 * ((l-1)/d);
  };

  for (int i = 0; i < q; ++i) {
    int s = 0, d = 0, k = 0;
    cin >> s >> d >> k;

    i64 ans = compute_query(s, d, k);
    cout << ans << " ";
  }
  cout << endl;
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
