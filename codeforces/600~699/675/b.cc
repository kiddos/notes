#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// a1 + b = a2 + c
// a3 + b = a4 + c
// a1 + a = a3 + d
// a2 + a = a4 + d

void solve() {
  int n = 0, a = 0, b = 0, c = 0, d = 0;
  cin >> n >> a >> b >> c >> d;

  int a1_count = 0;
  for (int a1 = 1; a1 <= n; ++a1) {
    int a2 = a1 + b - c;
    int a3 = a1 + a - d;
    int a4 = a2 + a - d;
    if (a2 >= 1 && a2 <= n && a3 >= 1 && a3 <= n && a4 >= 1 && a4 <= n) {
      a1_count++;
    }
  }

  i64 a5_count = n;
  i64 ans = a1_count * a5_count;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
