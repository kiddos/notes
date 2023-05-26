#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<ll> p = {0};
  for (int i = 0; i < n; ++i) p.push_back(p.back() + a[i]);

  auto ask = [&](int m) -> int {
    cout << "? " << m << " ";
    for (int i = 1; i <= m; ++i) {
      cout << i << " ";
    }
    cout << endl;
    int result = 0;
    cin >> result;
    return result;
  };

  int l = 0, r = n-1;
  int ans = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    ll result = ask(mid+1);
    if (result > p[mid+1]) {
      ans = mid+1;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  cout << "! " << ans << endl;
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
