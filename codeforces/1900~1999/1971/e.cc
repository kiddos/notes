#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, q = 0;
  cin >> n >> k >> q;
  vector<int> a(k+1);
  for (int i = 1; i <= k; ++i) cin >> a[i];
  vector<int> b(k+1);
  for (int i = 1; i <= k; ++i) cin >> b[i];

  for (int i = 0; i < q; ++i) {
    int d = 0;
    cin >> d;

    int idx = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
    if (d == a[idx]) {
      cout << b[idx] << " ";
    } else {
      i64 travel = a[idx+1] - a[idx];
      i64 time = b[idx+1] - b[idx];
      i64 total_time = b[idx] + time * (d - a[idx]) / travel;
      cout << total_time << " ";
    }
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
