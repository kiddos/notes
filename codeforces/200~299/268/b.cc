#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int c = 1;
  i64 ans = 0;
  for (int p = n; p >= 1; --p, ++c) {
    int incorrect = p - 1;
    ans += incorrect * c;
    ans++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
