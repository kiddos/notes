#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string pi = "3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825";
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string s;
    cin >> s;
    int i = 0;
    for (i = 0; i < s.length(); ++i) {
      if (s[i] != pi[i]) {
        break;
      }
    }
    cout << i << endl;
  }
  return 0;
}
