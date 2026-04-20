#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> c(n+1);
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    c[l]++;
    c[r]--;
  }
  for (int i = 1; i <= n; ++i) {
    c[i] += c[i-1];
  }
  c.resize(n);
  sort(c.rbegin(), c.rend());
  sort(a.rbegin(), a.rend());
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (i64)a[i] * c[i];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
