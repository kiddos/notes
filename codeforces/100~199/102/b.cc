#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int ans = 0;
  while (s.length() > 1) {
    int sum = 0;
    for (char ch : s) {
      sum += (ch - '0');
    }
    s = to_string(sum);
    ans++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
