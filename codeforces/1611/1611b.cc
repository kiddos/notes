#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
  if (a > b) swap(a, b);
  int diff = b - a;
  int diff_team = min(a, diff / 2);
  a -= diff_team;
  b -= diff_team * 3;
  return min(a / 2, b / 2) + diff_team;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t -- > 0) {
    int a = 0, b = 0;
    cin >> a >> b;
    int ans = solve(a, b);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
