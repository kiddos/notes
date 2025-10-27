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
  int idx = max_element(a.begin(), a.end()) - a.begin();
  int l = idx, r = idx;
  int x = n - 1;
  while (l - 1 >= 0 || r + 1 < n) {
    if (l > 0 && a[l - 1] == x) {
      l--;
      x--;
    } else if (r + 1 < n && a[r + 1] == x) {
      r++;
      x--;
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
