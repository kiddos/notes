#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<int> id(n);
  for (int i = 0; i < n; ++i) {
    cin >> id[i];
  }

  k--;
  i64 l = 0, r = n;
  i64 round = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 announce_before = (mid + 1) * mid / 2;
    if (announce_before <= k) {
      round = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  i64 annouce_before = (round + 1) * round / 2;
  k -= annouce_before;
  int ans = id[k];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
