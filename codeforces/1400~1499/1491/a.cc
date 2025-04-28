#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ones = 0;
  for (int i = 0; i < n; ++i) {
    ones += a[i] == 1;
  }
  for (int i = 0; i < q; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int x = 0;
      cin >> x;
      x--;
      if (a[x] == 1) {
        a[x] = 0;
        ones--;
      } else {
        a[x] = 1;
        ones++;
      }
    } else if (t == 2) {
      int k = 0;
      cin >> k;
      if (ones >= k) {
        cout << "1" << endl;
      } else {
        cout << "0" << endl;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
