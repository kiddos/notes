#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> c(4);
  for (int i = 1; i <= 3; ++i) {
    cin >> c[i];
  }
  vector<int> a(6);
  for (int i = 1; i <= 5; ++i) {
    cin >> a[i];
  }

  if (a[1] > c[1] || a[2] > c[2] || a[3] > c[3]) {
    cout << "NO" << endl;
    return;
  }
  c[1] -= a[1];
  c[2] -= a[2];
  c[3] -= a[3];
  int extra_paper = min(c[1], a[4]);
  int extra_plastic = min(c[2], a[5]);
  c[1] -= extra_paper;
  c[2] -= extra_plastic;
  a[4] -= extra_paper;
  a[5] -= extra_plastic;
  if (a[4] + a[5] <= c[3]) {
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
