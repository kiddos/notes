#include <bits/stdc++.h>

using namespace std;

void solve(string& s) {
  int n = s.length();
  for (int i = 1; i < n; ++i) {
    if (s[i-1] == 'R' && s[i] == 'L') {
      cout << "0" << endl;
      return;
    } else if (s[i-1] == 'L' && s[i] == 'R') {
      cout << i << endl;
      return;
    }
  }
  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    string s;
    cin >> n >> s;
    solve(s);
  }
  return 0;
}
