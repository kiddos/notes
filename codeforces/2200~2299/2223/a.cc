#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_valid(const string& s) {
  int n = s.length();
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      st.push(i);
    } else if (s[i] == ')') {
      if (st.empty()) {
        return false;
      }
      st.pop();
    }
  }
  return st.empty();
}

void solve() {
  int n = 0;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;

  string a, b;
  for (int i = 0, turn = 0; i < n; ++i) {
    if (s1[i] == s2[i]) {
      a.push_back(s1[i]);
      b.push_back(s2[i]);
    } else {
      if (turn == 0) {
        a.push_back('(');
        b.push_back(')');
      } else if (turn == 1) {
        b.push_back('(');
        a.push_back(')');
      }
      turn ^= 1;
    }
  }

  if (is_valid(a) && is_valid(b)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
