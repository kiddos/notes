#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  i64 ans = 0;
  if (n % 2 == 0) {
    ans = n / 2;
  } else {
    ans = (-n-1) / 2;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
