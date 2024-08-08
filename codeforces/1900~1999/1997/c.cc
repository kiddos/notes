#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  stack<int> st;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '_') {
      if (st.empty()) {
        st.push(i);
      } else {
        ans += i - st.top();
        st.pop();
      }
    } else if (s[i] == '(') {
      st.push(i);
    } else if (s[i] == ')') {
      ans += i - st.top();
      st.pop();
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
