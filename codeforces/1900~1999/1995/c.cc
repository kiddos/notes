#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using ld = long double;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i < n; ++i) {
    if (a[i] == 1 && a[i-1] > 1) {
      cout << "-1" << endl;
      return;
    }
  }

  int start = 0;
  while (start < n && a[start] == 1) {
    start++;
  }

  vector<i64> sq(n);
  for (int i = start + 1; i < n; ++i) {
    i64 s = sq[i-1];
    i64 a1 = a[i-1];
    i64 a2 = a[i];
    while (a1 != 1 && a1 * a1 <= a2) {
      s--;
      a1 *= a1;
    }
    while (a2 < a1) {
      s++;
      a2 *= a2;
    }
    sq[i] = max(s, 0LL);
  }

  i64 ans = accumulate(sq.begin(), sq.end(), 0LL);
  cout << ans << endl;
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
