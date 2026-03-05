#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 101001
// ^ ^^^
// 000111

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string s2 = s;
  sort(s2.begin(), s2.end());
  if (s == s2) {
    cout << "Bob" << endl;
    return;
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (s[i] != s2[i]) {
      ans.push_back(i+1);
    }
  }
  cout << "Alice" << endl;
  cout << ans.size() << endl;
  for (int idx : ans) {
    cout << idx << " ";
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
