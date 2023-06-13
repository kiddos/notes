#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    int special = (i > 1 && a[i-1] >= a[i] && i+1 <= n && a[i] >= a[i+1]);
    p[i] = p[i-1] + special;
  }


  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    int len = r-l+1;
    if (len <= 2) {
      cout << len << endl;
    } else {
      int special = p[r-1] - p[l];
      int total = r - l + 1 - special;
      cout << total << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
