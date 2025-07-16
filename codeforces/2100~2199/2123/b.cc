#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, j = 0, k = 0;
  cin >> n >> j >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (k > 1) {
    cout << "YES" << endl;
    return;
  }
  j--;
  int max_val = *max_element(a.begin(), a.end());
  if (max_val == a[j]) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
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
