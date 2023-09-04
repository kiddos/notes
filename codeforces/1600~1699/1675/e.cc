#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  auto change_all = [&](char from, char to) {
    for (int i = 0; i < n; ++i) {
      if (s[i] <= from) {
        s[i] = min(s[i], to);
      }
    }
  };

  vector<int> require(n);
  for (int i = 0; i < n; ++i) {
    int op = s[i] - 'a';
    require[i] = op;
    if (i > 0) require[i] = max(require[i], require[i-1]);
  }

  for (int i = 0; i < n; ++i) {
    if (require[i] > k) {
      if (i > 0) {
        change_all('a' + require[i-1], 'a');
        k -= require[i-1];
      }

      char to = s[i] - min(k, s[i] - 'a');
      change_all(s[i], to);
      break;
    }

    if (i == n-1 && require[i] <= k) {
      change_all('a' + require[i], 'a');
    }
  }

  cout << s << endl;
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
