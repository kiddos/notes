#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  set<string> found;
  for (int i = 0; i < n; ++i) {
    for (int k = 1; k <= 4 && i+k <= n; ++k) {
      string sub = s.substr(i, k);
      found.insert(sub);
    }
  }

  function<bool(string&,int)> permute = [&](string& x, int i) -> bool {
    if (i == (int)x.length()) {
      return !found.count(x);
    }

    for (char ch = 'a'; ch <= 'z'; ++ch) {
      x[i] = ch;
      if (permute(x, i+1)) {
        return true;
      }
    }
    return false;
  };

  for (int len = 1; len < 4; ++len) {
    string t(len, ' ');
    if (permute(t, 0)) {
      cout << t << endl;
      return;
    }
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
