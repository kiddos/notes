#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  string y = "Yes";
  int i = y.find(s[0]);
  if (i == string::npos) {
    cout << "NO" << endl;
    return;
  }

  for (int k = 0; k < s.length(); ++k) {
    if (s[k] != y[i]) {
      cout << "NO" << endl;
      return;
    }
    i = (i+1) % 3;
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
