#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 c = 0, v0 = 0, v1 = 0, a = 0, l = 0;
  cin >> c >> v0 >> v1 >> a >> l;

  i64 can_read = v0;
  i64 to_read = c;
  int ans = 0;
  while (true) {
    ans++;
    to_read -= can_read;
    if (to_read <= 0) {
      break;
    }
    can_read = min(can_read + a, v1);
    to_read += l;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
