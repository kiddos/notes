#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, h = 0;
  cin >> n >> h;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > h) {
      ans += 2;
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
