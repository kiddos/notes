#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int l = 0, r = n-1;
  int ans = 0;
  while (l <= r) {
    if (p[r] + p[l] <= x) {
      r--;
      l++;
    } else {
      r--;
    }
    ans++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
