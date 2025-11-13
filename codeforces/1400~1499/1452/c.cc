#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  stack<int> st1, st2;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      st1.push(i);
    } else if (s[i] == ')') {
      if (!st1.empty()) {
        st1.pop();
        ans++;
      }
    } else if (s[i] == '[') {
      st2.push(i);
    } else if (s[i] == ']') {
      if (!st2.empty()) {
        st2.pop();
        ans++;
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
