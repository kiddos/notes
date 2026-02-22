#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int ans = stoi(s);
  for (int i = n-2; i < n; ++i) {
    string s2 = s.substr(0, i) + s.substr(i+1);
    ans = max(ans, stoi(s2));
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
