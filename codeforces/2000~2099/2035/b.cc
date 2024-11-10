#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n == 1) {
    cout << "-1" << endl;
  } else if (n == 2) {
    cout << "66" << endl;
  } else if (n == 3) {
    cout << "-1" << endl;
  } else if (n == 4) {
    cout << "3366" << endl;
  } else if (n == 5) {
    cout << "36366" << endl;
  } else if (n % 2 == 0) {
    string ans = string(n-4, '3') + "3366";
    cout << ans << endl;
  } else if (n % 2 == 1) {
    string ans = string(n-5, '3') + "36366";
    cout << ans << endl;
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
