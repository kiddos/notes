#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int min_d = *min_element(a.begin(), a.end());

  i64 p = 1;
  bool added = false;
  for (int i = 0; i < n; ++i) {
    if (a[i] == min_d) {
      if (!added) {
        a[i]++;
        added = true;
      }
    }

    p *= a[i];
  }
  cout << p << endl;
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
