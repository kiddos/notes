#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int last = 0;
  int ans = 0;
  for (char ch : s) {
    int c = ch - 'a';
    int dist = min({26 - last + c, last + 26 - c, abs(last - c)});
    ans += dist;
    last = c;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
