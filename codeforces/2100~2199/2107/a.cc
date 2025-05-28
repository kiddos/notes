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
  vector<int> suff(n+1);
  for (int i = n-1; i >= 0; --i) {
    suff[i] = gcd(a[i], suff[i+1]);
  }
  
  vector<int> ans(n, 1);
  bool found = false;
  int g = 0;
  for (int i = 0; i < n; ++i) {
    int other = gcd(g, suff[i+1]);
    if (a[i] != other) {
      ans[i] = 2;
      found = true;
      break;
    }
    g = gcd(g, a[i]);
  }

  if (!found) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
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
