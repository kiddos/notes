#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int l = 0, r = n-1;
  int total_alice = 0, total_bob = 0;
  int alice = 0, bob = 0;
  int turn = 0;
  int ans = 0;
  while (l <= r) {
    if (turn == 0) {
      alice = 0;
      while (l <= r && alice <= bob) {
        total_alice += a[l];
        alice += a[l];
        l++;
      }
    } else {
      bob = 0;
      while (r >= l && bob <= alice) {
        total_bob += a[r];
        bob += a[r];
        r--;
      }
    }

    ans++;
    turn ^= 1;
  }

  cout << ans << " " << total_alice << " " << total_bob << endl;
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
