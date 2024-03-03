#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int,int> interval;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && a[j] == a[i]) {
      j++;
    }
    interval[j-1] = i;
    i = j;
  }

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;
    auto it = interval.lower_bound(r);
    if (it != interval.end() && it->second <= l) {
      cout << "-1 -1" << endl;
    } else {
      if (it != interval.end()) {
        cout << it->second << " " << r+1 << endl;
      } else {
        cout << r << " " << r+1 << endl;
      }
    }
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
