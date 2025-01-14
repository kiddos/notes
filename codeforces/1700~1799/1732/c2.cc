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

  auto find_first_largest = [&](int low, int high, i64 max_f) -> int {
    int l = low, r = high;
    int index = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (f(low, mid) == max_f) {
        r = mid - 1;
        index = mid;
      } else {
        l = mid + 1;
      }
    }
    return index;
  };

  for (int i = 0; i < q; ++i) {
    i64 max_f = f(L[i], R[i]);
    if (max_f == 0) {
      cout << L[i] << " " << L[i] << endl;
      continue;
    }
    int r = find_first_largest(L[i], R[i], max_f);
    pair<int,int> ans = {L[i], r};
    for (int l = L[i]; l <= r; ++l) {
      int r2 = find_first_largest(l, R[i], max_f);
      if (r2 >= 0 && r2-l+1 < ans.second - ans.first + 1) {
        ans = {l, r2};
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
