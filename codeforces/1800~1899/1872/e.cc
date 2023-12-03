#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  string s;
  cin >> s;

  int ones_x = 0, zeros_x = 0;
  vector<int> p = {0};
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      zeros_x ^= a[i];
    } else if (s[i] == '1') {
      ones_x ^= a[i];
    }
    p.push_back(p.back() ^ a[i]);
  }

  int q = 0;
  cin >> q;
  while (q -- > 0) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int l = 0, r = 0;
      cin >> l >> r;

      int x = p[r] ^ p[l-1];
      ones_x ^= x;
      zeros_x ^= x;
    } else if (type == 2) {
      int g = 0;
      cin >> g;

      if (g == 0) {
        cout << zeros_x << " ";
      } else if (g == 1) {
        cout << ones_x << " ";
      }
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
