#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int get_ops(int a, int b) {
  int ans = 0;
  while (a > 0) {
    a /= b;
    ans++;
  }
  return ans;
}

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;

  int ans = 0, base = 0;
  if (b == 1) {
    base = get_ops(a, b+1) + 1;
  } else {
    base = get_ops(a, b);
  }
  ans = base;
  for (int i = 1; i <= base; ++i) {
    ans = min(ans, get_ops(a, b+i) + i);
  }
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
