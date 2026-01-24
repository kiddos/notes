#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int left = 240 - k;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int need = i * 5;
    if (left < need) {
      break;
    }
    left -= need;
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
