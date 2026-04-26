#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "-1" << endl;
  } else {
    cout << max(a.length(), b.length()) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
