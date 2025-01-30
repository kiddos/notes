#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  i64 missing = 0;
  int missing_count = 0;
  vector<i64> extra;
  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      missing += b[i] - a[i];
      missing_count++;
    } else {
      extra.push_back(a[i] - b[i]);
    }
  }

  if (missing_count > 1) {
    cout << "NO" << endl;
    return;
  }
  i64 take = *min_element(extra.begin(), extra.end());
  if (missing > take) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
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
