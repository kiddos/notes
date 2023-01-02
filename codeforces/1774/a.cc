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
    int value = s[0] - '0';
    string ans;
    for (int i = 1; i < n; ++i) {
      int d = s[i] - '0';
      if (d && value) {
        ans.push_back('-');
        value -= d;
      } else {
        value += d;
        ans.push_back('+');
      }
    }
    cout << ans << endl;
  }
  return 0;
}
