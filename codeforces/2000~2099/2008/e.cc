#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> c1(n+1, vector<int>(26));
  vector<vector<int>> c2(n+1, vector<int>(26));
  for (int i = 0; i < n; ++i) {
    int ch = s[i]-'a';
    if (i % 2 == 0) {
      c1[i+1][ch]++;
    } else {
      c2[i+1][ch]++;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int ch = 0; ch < 26; ++ch) {
      c1[i][ch] += c1[i-1][ch];
      c2[i][ch] += c2[i-1][ch];
    }
  }

  if (n % 2 == 0) {
    int p = *max_element(c1[n].begin(), c1[n].end());
    int q = *max_element(c2[n].begin(), c2[n].end());
    int ans = n - p - q;
    cout << ans << endl;
  } else {
    int ans = n;
    for (int i = 0; i < n; ++i) {
      // remove the ith character
      vector<int> x(26), y(26);
      for (int ch = 0; ch < 26; ++ch) {
        x[ch] += c1[i][ch];
        y[ch] += c2[i][ch];
        x[ch] += c2[n][ch] - c2[i+1][ch];
        y[ch] += c1[n][ch] - c1[i+1][ch];
      }
      int p = *max_element(x.begin(), x.end());
      int q = *max_element(y.begin(), y.end());
      ans = min(ans, n-1 - p - q + 1);
    }
    cout << ans << endl;
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
