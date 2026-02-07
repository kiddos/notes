#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int diag = min(n, m);
  if (diag % 2 == 1) {
    cout << "Akshat" << endl;
  } else {
    cout << "Malvika" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
