#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s, t;
  cin >> s >> t;

  if (s[0] != t[0] || s.back() != t.back()) {
    cout << "-1" << endl;
    return;
  }

  int z1 = 0, z2 = 0;
  for (int i = 1; i < n; ++i) {
    string a = s.substr(i-1, 2);
    string b = t.substr(i-1, 2);
    if (a == "01") {
      z1++;
    } else if (a == "10") {
      z2++;
    }

    if (b == "01") {
      z1--;
    } else if (b == "10") {
      z2--;
    }
  }

  if (z1 != 0 || z2 != 0) {
    cout << "-1" << endl;
    return;
  }

  ll ans = 0;
  int j = 0;
  while (j < n && t[j] == '1') j++;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '1' && s[i-1] == '0') {
      while (j < n && t[j] == '0') j++;
      // cout << "i=" << i << ", j=" << j << endl;
      ans += abs(i-j);
      while (j < n && t[j] == '1') j++;
    }
  }

  j = n-1;
  while (j >= 0 && t[j] == '1') j--;
  for (int i = n-2; i >= 0; --i) {
    if (s[i] == '1' && s[i+1] == '0') {
      while (j >= 0 && t[j] == '0') j--;
      ans += abs(i-j);
      while (j >= 0 && t[j] == '1') j--;
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
