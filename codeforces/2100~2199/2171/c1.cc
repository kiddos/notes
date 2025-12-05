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
  int last = -1;
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      last = i;
    }
    x ^= a[i];
    y ^= b[i];
  }
  if (last == -1) {
    cout << "Tie" << endl;;
    return;
  }
  if (last % 2 == 0) {
    // Ajisai last move
    if (x == y) {
      cout << "Tie" << endl;
    } else {
      cout << "Ajisai" << endl;
    }
  } else {
    // Mai last move
    if (x == y) {
      cout << "Tie" << endl;
    } else {
      cout << "Mai" << endl;
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
