#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];


  vector<array<bool, 2>> counts(k+1, {false, false});
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 1 && a[i] <= k) {
      counts[a[i]][0] = true;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (b[i] >= 1 && b[i] <= k) {
      counts[b[i]][1] = true;
    }
  }

  int a_count = 0, b_count = 0;
  for (int i = 1; i <= k; ++i) {
    if (!counts[i][0] && !counts[i][1]) {
      cout << "NO" << endl;
      return;
    }
    if (counts[i][0]) a_count++;
    if (counts[i][1]) b_count++;
  }

  if (a_count >= k/2 && b_count >= k/2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
