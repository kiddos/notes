#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  for (char ch : s) {
    if (ch == 'H' || ch == 'Q' || ch == '9') {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
