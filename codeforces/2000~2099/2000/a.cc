#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a;
  cin >> a;
  if (a.length() < 3) {
    cout << "NO" << endl;
    return;
  }

  int base = stoi(a.substr(0, 2));
  int x = stoi(a.substr(2));
  if (base != 10) {
    cout << "NO" << endl;
    return;
  }
  if (a[2] == '0') {
    cout << "NO" << endl;
    return;
  }
  if (x < 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
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
