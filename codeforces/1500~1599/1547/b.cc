#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  auto i = s.find('a');
  if (i == string::npos) {
    cout << "NO" << endl;
    return;
  }

  int n = s.length();
  int l = i, r = i;
  char c = 'a';
  for (int k = 1; k < n; ++k, ++c) {
    if (l-1 >= 0 && s[l-1] == c+1) {
      l--;
    } else if (r+1 < n && s[r+1] == c+1) {
      r++;
    } else {
      cout << "NO" << endl;
      return;
    }
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
