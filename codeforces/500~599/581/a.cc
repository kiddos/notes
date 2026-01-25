#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  int common = min(a, b);
  a -= common;
  b -= common;
  int same = a / 2 + b / 2;
  cout << common << " " << same << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
