#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;

  transform(s.begin(), s.end(), s.begin(), ::toupper);
  if (s == "YES") {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
