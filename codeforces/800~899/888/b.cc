#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;

  cin >> s;

  pair<int,int> pos = {0, 0};
  for (char ch : s) {
    if (ch == 'L') {
      pos.first -= 1;
    } else if (ch == 'R') {
      pos.first += 1;
    } else if (ch == 'U') {
      pos.second += 1;
    } else if (ch == 'D') {
      pos.second -= 1;
    }
  }
  int incorrect = abs(pos.first) + abs(pos.second);
  int ans = n - incorrect;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
