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
  int last = -1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      if (last < 0) {
        ans++;
        last = i;
      } else {
        ans += min(i-last, 2);
        last = i;
      }
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
