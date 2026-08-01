#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> f(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }

  sort(f.begin(), f.end());
  int ans = 0;
  for (int i = n-1; i >= 0; i -= k) {
    ans += (f[i] - 1) * 2;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
