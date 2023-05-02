#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  char min_char = *min_element(s.begin(), s.end());
  for (int i = n-1; i >= 1; --i) if (s[i] == min_char) {
    cout << string(1, min_char) + s.substr(0, i) + s.substr(i+1) << endl;
    return;
  }
  cout << s << endl;
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
