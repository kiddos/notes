#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int minimum_change(const string& s, const string& s0) {
  int n = s.length(), k = s0.length();
  int ans = n;
  for (int i = 0; i <= n-k; ++i) {
    int diff = 0;
    for (int j = 0; j < k; ++j) {
      diff += s[j+i] != s0[j];
    }
    ans = min(ans, diff);
  }
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  string t = "RGB";
  int ans = n;
  for (int offset = 0; offset < 3; ++offset) {
    string s0;
    for (int i = 0; i < k; ++i) {
      s0.push_back(t[(i+offset)%3]);
    }

    int result = minimum_change(s, s0);
    ans = min(ans, result);
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
