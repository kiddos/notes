#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> L(q), R(q);
  for (int i = 0; i < q; ++i) {
    cin >> L[i] >> R[i];
  }
  for (int k = 0; k < q; ++k) {
    i64 sum = 0, x = 0;
    i64 best_f = 0;
    pair<int,int> ans = {L[k], L[k]};
    for (int i = L[k]; i <= R[k]; ++i) {
      sum += a[i];
      x ^= a[i];
      if (sum-x > best_f) {
        best_f = sum-x;
        ans.second = i;
      }
    }

    sum = 0, x = 0;
    for (int i = L[k], j = L[k]; i <= R[k]; ++i) {
      sum += a[i];
      x ^= a[i];
      while (j <= i && sum - x == best_f) {
        int len = i-j+1;
        if (len < ans.second-ans.first+1) {
          ans = {j, i};
        }
        sum -= a[j];
        x ^= a[j];
        j++;
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
