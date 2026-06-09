#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  vector<int> ans(10, -1);
  for (int idx = 1; idx <= 1000000; ++idx) {
    a = a * 10;
    int d = a / b;
    a %= b;
    if (ans[d] < 0) {
      ans[d] = idx;
    }
  }
  cout << ans[c] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
