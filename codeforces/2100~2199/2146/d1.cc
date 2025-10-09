#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;
  if (r == 0) {
    cout << "0" << endl;
    cout << "0" << endl;
    return;
  }

  int len = r+1;
  int p2 = 1;
  while (p2*2 <= len) {
    p2 *= 2;
  }

  int mask = p2-1;
  vector<vector<int>> group(p2);
  for (int i = 0; i <= r; ++i) {
    group[(i & mask)].push_back(i);
  }

  // for (int i = 0; i <= mask; ++i) {
  //   cout << i << ":";
  //   for (int val : group[i]) {
  //     cout << val << " ";
  //   }
  //   cout << endl;
  // }

  vector<int> a(r+1);
  for (int i = 0; i <= r; ++i) {
    int m = mask;
    while (group[(m^i) & m].empty()) {
      m >>= 1;
    }
    int target_mask = (m ^ i) & m;
    // cout << "target_mask=" << target_mask << endl;
    a[i] = group[target_mask].back();
    group[target_mask].pop_back();
  }

  i64 ans = 0;
  for (int i = 0; i <= r; ++i) {
    ans += (a[i] | i);
  }

  cout << ans << endl;
  for (int i = 0; i <= r; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
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
