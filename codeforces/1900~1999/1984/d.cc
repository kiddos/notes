#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> z_function(const string& s) {
  int n = s.length();
  int l = 0, r = 0;
  vector<int> z(n);
  for (int i = 1; i < n; ++i) {
    if (i < r) {
      z[i] = min(r-i, z[i-l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i+z[i]]) {
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
  vector<int> indices;
  // string without_a;
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'a') {
      indices.push_back(i);
      // without_a.push_back(s[i]);
    }
  }

  if (indices.empty()) {
    cout << n-1 << endl;
    return;
  }

  int m = indices.size();
  string s2 = s.substr(indices[0]);
  vector<int> z = z_function(s2);
  i64 ans = 0;
  for (int len = 1; len <= m; ++len) {
    if (m % len == 0) {
      bool valid = true;
      int size = indices[len-1] - indices[0] + 1;
      for (int i = len; i < m; i += len) {
        if (z[indices[i] - indices[0]] < size) {
          valid = false;
          break;
        }
      }

      if (valid) {
        // cout << "len=" << len << endl;
        int p = indices[0];
        for (int i = len; i < m; i += len) {
          // cout << indices[i] - indices[i-1] - 1 << endl;
          p = min(p, indices[i] - indices[i-1] - 1);
        }
        int s = n + 1;
        for (int i = m-len-1; i >= 0; i -= len) {
          // cout << indices[i + 1] - indices[i] - 1 << endl;
          s = min(s, indices[i + 1] - indices[i] - 1);
        }
        // cout << "prefix=" << p << ", suffix=" << s << endl;
        for (int j = 0; j <= p; ++j) {
          int suffix = min(max(s - j, 0), n - indices.back() - 1);
          ans += suffix + 1;
          // cout << "j=" << j << ", add=" << suffix + 1 << endl;
        }
      }
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
