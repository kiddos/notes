#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  i64 ans = 0;
  i64 covered = 0;
  for (int i = n-1; i >= 1; --i) {
    ans += a[i] - 1;
    if (a[i] >= covered+1) {
      covered++;
    }
  }
  i64 keep = max(a[0] - covered, 1LL);
  ans += a[0] - keep;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
