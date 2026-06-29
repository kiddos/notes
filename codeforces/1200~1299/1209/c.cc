#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string ans(n, '1');
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && s[st.top()] > s[i]) {
      ans[st.top()] = '2';
      st.pop();
    }
    st.push(i);
  }

  int index = -1;
  for (int i = 0; i < n; ++i) {
    if (ans[i] == '2') {
      index = i;
      break;
    }
  }

  if (index >= 0) {
    for (int i = n-1; i >= 0; --i) {
      if (ans[i] == '1' && s[i] > s[index]) {
        ans[i] = '2';
      }
    }
  }

  string first, second;
  for (int i = 0; i < n; ++i) {
    if (ans[i] == '1') {
      first.push_back(s[i]);
    } else if (ans[i] == '2') {
      second.push_back(s[i]);
    }
  }

  string combine = first + second;
  string sorted = combine;
  sort(sorted.begin(), sorted.end());
  if (combine != sorted) {
    cout << "-" << endl;
    return;
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
