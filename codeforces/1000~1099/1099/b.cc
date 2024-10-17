#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  i64 s = sqrt(n);
  i64 a = s, b = s;
  while (a * b < n) {
    a++;
    if (a * b >= n) {
      break;
    }
    b++;
  }

  int ans = a + b;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
