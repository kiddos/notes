#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> mods(n);
  i64 p = 0;
  i64 ans = 0;
  mods[0] = 1;
  for (int i = 0; i < n; ++i) {
    p += a[i];
    p %= n;
    p = (p + n) % n;
    ans += mods[p];
    mods[p]++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

