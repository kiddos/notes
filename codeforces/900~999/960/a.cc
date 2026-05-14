#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> count(3);
  for (int i = 0; i < n; ++i) {
    count[s[i]-'a']++;
  }
  string s2 = s;
  sort(s2.begin(), s2.end());
  if (s2 != s) {
    cout << "NO" << endl;
    return;
  }

  if (count[0] != count[2] && count[1] != count[2]) {
    cout << "NO" << endl;
    return;
  }

  if (count[0] == 0 || count[1] == 0) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
