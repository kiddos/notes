#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  set<int> colors;
  for (int i = 0; i < 4; ++i)  {
    int s = 0;
    cin >> s;
    colors.insert(s);
  }
  int ans = max(4 - (int) colors.size(), 0);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
