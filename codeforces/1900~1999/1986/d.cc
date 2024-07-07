#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  
  if (n == 2) {
    int ans = stoi(s);
    cout << ans << endl;
  } else if (n == 3) {
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(2));
    int c = stoi(s.substr(0, 1));
    int d = stoi(s.substr(1));
    int ans = min({a * b, a + b, c * d, c + d});
    cout << ans << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        cout << "0" << endl;
        return;
      }
    }

    int ans = numeric_limits<int>::max();
    for (int i = 1; i < n; ++i) {
      int val = stoi(s.substr(i-1, 2));
      for (int j = 0; j < i-1; ++j) {
        if (s[j] != '1') {
          val += s[j] - '0';
        }
      }
      for (int j = i+1; j < n; ++j) {
        if (s[j] != '1') {
          val += s[j] - '0';
        }
      }
      ans = min(ans, val);
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
