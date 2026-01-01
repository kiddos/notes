#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string st;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!st.empty() && st.back() == s[i]) {
      ans++;
    } else {
      st.push_back(s[i]);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
