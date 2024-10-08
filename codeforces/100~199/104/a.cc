#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int x = n - 10;
  if (x <= 0) {
    cout << "0" << endl;
    return;
  }

  if (x >= 1 && x <= 9) {
    cout << "4" << endl;
    return;
  }
  if (x == 10) {
    cout << "15" << endl;
    return;
  }
  if (x == 11) {
    cout << "4" << endl;
    return;
  }
  cout << "0" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
