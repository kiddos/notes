#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  auto first_closed = s.find(')');
  auto last_opened = s.rfind('(');
  if (last_opened < first_closed) {
    cout << "-1" << endl;
    return;
  }

  string ans;
  for (int i = 0; i < n; ++i) {
    if (i != (int)first_closed && i != (int)last_opened) {
      ans.push_back(s[i]);
    }
  }

  int len = ans.length();
  bool better = false;
  for (int i = 0; i < len; ++i) {
    if (ans[i] != s[i]) {
      if (ans[i] == '(' && s[i] == ')') {
        better = true;
      }
      break;
    }
  }

  if (better) {
    cout << ans.length() << endl;
  } else {
    cout << "-1" << endl;
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
