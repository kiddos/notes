#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int offset = 'a' - 'A';
  if (s[0] >= 'a' && s[0] <= 'z') {
    s[0] -= offset;
  }
  cout << s << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
