#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) cin >> w[i];
  i64 alice = 0, bob = 0;
  int ans = 0;
  for (int i = n-1, j = 0; i >= j; --i) {
    bob += w[i];
    while (j < i && alice < bob) {
      alice += w[j++];
    }

    if (alice == bob) {
      ans = max(ans, j + n-i);
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
