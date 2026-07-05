#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int longest_regular(const string& s, vector<bool> skip) {
  int n = s.length();
  int ans = 0;
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    if (skip[i]) {
      continue;
    }
    if (s[i] == '(') {
      st.push(i);
    } else if (s[i] == ')') {
      if (!st.empty()) {
        st.pop();
        ans += 2;
      }
    }
  }
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<bool> skip(n);
  int longest = longest_regular(s, skip);
  for (int i = 0; i < n && k > 0; ++i) {
    skip[i] = true;
    int new_len = longest_regular(s, skip);
    if (new_len < longest) {
      longest = new_len;
      k--;
    } else {
      skip[i] = false;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << skip[i];
  }
  cout << endl;
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
