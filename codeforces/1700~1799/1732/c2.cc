#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> L(q), R(q);
  for (int i = 0; i < q; ++i) {
    cin >> L[i] >> R[i];
  }

  vector<i64> sum = a;
  for (int i = 1; i <= n; ++i) {
    sum[i] += sum[i-1];
  }
  vector<i64> x = a;
  for (int i = 1; i <= n; ++i) {
    x[i] ^= x[i-1];
  }

  auto f = [&](int l, int r) -> i64 {
    return (sum[r] - sum[l-1]) - (x[r] ^ x[l-1]);
  };

  for (int i = 0; i < q; ++i) {
    i64 max_f = f(L[i], R[i]);
    if (max_f == 0) {
      cout << L[i] << " " << L[i] << endl;
      continue;
    }

    pair<int,int> ans = {L[i], R[i]};
    int best = f(L[i], R[i]);
    for (int j = L[i]; j <= min(L[i] + 31, R[i]); ++j) {
      int l = j, r = R[i];
      int idx = -1;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int f2 = f(j, mid);
        if (f2 == best) {
          idx = mid;
          r = mid-1;
        } else {
          l = mid+1;
        }
      }
      if (idx >= 0) {
        int len = idx-j+1;
        if (len < ans.second-ans.first+1) {
          ans = {j, idx};
        }
      }
    }
    cout << ans.first << " " << ans.second << endl;
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
