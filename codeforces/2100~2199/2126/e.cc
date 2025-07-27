#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  if (s[0] != p.back()) {
    cout << "NO" << endl;
    return;
  }

  int g = p.back();
  vector<int> p2(n), s2(n);
  for (int i = 0; i < n; ++i) {
    p2[i] = p[i] / g;
    s2[i] = s[i] / g;
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0 && p[i-1] % p[i] != 0) {
      cout << "NO" << endl;
      return;
    }
    if (i + 1 < n && s[i+1] % s[i] != 0) {
      cout << "NO" << endl;
      return;
    }
    if (i > 0 && gcd(p[i-1] / p[i], s2[i]) != 1) {
      cout << "NO" << endl;
      return;
    }
    if (i + 1 < n && gcd(s[i+1] / s[i], p2[i]) != 1) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
