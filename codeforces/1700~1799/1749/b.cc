#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  ll ans = 0;
  int l = 0, r = n-1;
  while (l <= r) {
    int left = b[l], right = b[r];
    if (left <= right) {
      ans += a[l++];
      if (l < n) a[l] += left;
    } else {
      ans += a[r--];
      if (r >= 0) a[r] += right;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
