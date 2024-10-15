#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 l = 0, r = 0;
  cin >> l >> r;
  cout << "YES" << endl;
  for (i64 i = l; i+1 <= r; i += 2) {
    cout << i << " " << i+1 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
