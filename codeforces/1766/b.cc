#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<string, int> found;
    bool ans = false;
    for (int i = 0; i < n-1; ++i) {
      string sub = s.substr(i, 2);
      if (found.count(sub) && i-found[sub] >= 2) {
        ans = true;
        break;
      }
      if (!found.count(sub)) {
        found[sub] = i;
      }
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
