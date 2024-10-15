#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  pair<int,int> pos = {0,  0};
  int ans = 0;
  int where = 0;
  for (char ch : s) {
    if (ch == 'U') {
      pos.second += 1;
    } else if (ch == 'R') {
      pos.first += 1;
    }

    int w = where;
    if (pos.first > pos.second) {
      where = 1;
    } else if (pos.first < pos.second) {
      where = -1;
    }
    if (w == -where) {
      ans++;
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
