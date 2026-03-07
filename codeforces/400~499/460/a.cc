#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int l = 0, r = 1000;
  int ans = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    int new_socks = (mid-1) / m;
    int total = n + new_socks;
    if (total >= mid) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
