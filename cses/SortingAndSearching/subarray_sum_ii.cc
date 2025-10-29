#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<i64,int> prefix = {{0, 1}};
  i64 p = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    p += a[i];
    i64 t = p - x;
    if (prefix.count(t)) {
      ans += prefix[t];
    }
    prefix[p]++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

