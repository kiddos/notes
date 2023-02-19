#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    string s;
    cin >> n >> s;
    if (n > 2) cout << "NO\n";
    else {
      if (s != "00" && s != "11") {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  cout << flush;
  return 0;
}
