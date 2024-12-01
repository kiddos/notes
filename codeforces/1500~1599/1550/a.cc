#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int s = 0;
  cin >> s;
  int l = 1, r = s;
  int ans = s;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    int top = 2 * mid - 1;
    int sum = (top + 1) * mid / 2;
    if (sum >= s) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid +1;
    }
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
