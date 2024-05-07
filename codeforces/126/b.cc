#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> z_function(const string& s) {
  int n = s.length();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  vector<int> z = z_function(s);

  set<int> lengths;
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (z[i] == 0) continue;

    if (z[i] + i == n) {
      auto it = lengths.lower_bound(z[i]);
      if (it != lengths.end()) {
        ans = max(ans, z[i]);
      }
    }
    lengths.insert(z[i]);
  }

  if (ans == 0) {
    cout << "Just a legend" << endl;
  } else {
    cout << s.substr(0, ans) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
