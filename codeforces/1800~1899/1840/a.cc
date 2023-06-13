#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  string ans;
  while (i < n) {
    int j = i+1;
    while (j < n && s[j] != s[i]) {
      j++;
    }
    ans.push_back(s[i]);
    i = j+1;
  }

  cout << ans << endl;
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
