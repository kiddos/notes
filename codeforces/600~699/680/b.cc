#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0;
  cin >> n >> a;
  vector<int> t(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }
  int ans = 0;
  if (t[a]) {
    ans++;
  }
  int l = a - 1, r = a + 1;
  while (l >= 1 && r <= n) {
    if (t[l] && t[r]) {
      ans += 2;
    }
    l--;
    r++;
  }
  while (r <= n) {
    ans += t[r++];
  }
  while (l >= 1) {
    ans += t[l--];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
