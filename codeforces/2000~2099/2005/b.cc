#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());

  for (int i = 0; i < q; ++i) {
    int a = 0;
    cin >> a;
    auto it = upper_bound(b.begin(), b.end(), a);
    int ans = 0;

    if (it == b.begin()) {
      // escape to first room
      ans = *it - 1;
    } else {
      int room1 = *prev(it);
      if (it == b.end()) {
        // escape to last room
        ans = n - room1;
      } else {
        // escape to middle
        int room2 = *it;
        int middle = (room1 + room2) / 2;
        ans = min(room2 - middle, middle - room1);
      }
    }
    cout << ans << endl;
  }
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
