#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> z_function(const string& s) {
  int n = s.length();
  vector<int> z(n);

  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i < r) {
      z[i] = min(r-i, z[i-l]);
    }
    while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
      z[i]++;
    }
    if (i+z[i] > r) {
      r = i+z[i];
      l = i;
    }
  }
  return z;
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<int> z = z_function(s);
  int ans = n;
  for (int i = 1; i < n; ++i) {
    int prefix_len = i;
    if (z[i] >= prefix_len) {
      int j = i + prefix_len;
      ans = min(ans, prefix_len + 1 + (n-j));
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
