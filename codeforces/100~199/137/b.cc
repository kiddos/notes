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
  vector<bool> found(n+1);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 1 && a[i] <= n) {
      if (!found[a[i]]) {
        found[a[i]] = true;
      } else {
        ans++;
      }
    } else {
      ans++;
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
