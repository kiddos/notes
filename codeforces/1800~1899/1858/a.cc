#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  i64 anna = (c+1) / 2 + a;
  i64 katie = c / 2 + b;

  if (anna > katie) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
