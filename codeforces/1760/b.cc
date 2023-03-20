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
    int ans = 0;
    for (char ch  : s) {
      ans = max(ans, ch-'a'+1);
    }
    cout << ans << endl;
  }
  return 0;
}
