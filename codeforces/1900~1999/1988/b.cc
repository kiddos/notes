#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  if (s[0] == '1' && s.back() == '1') {
    cout << "YES" << endl;
    return;
  }

  if (s.find("11") == string::npos) {
    cout << "NO" << endl;
    return;
  }

  int l = s.find("11");
  int r = s.rfind("11");
  if ((l != r) || (l != n-1 && s.back() == '1') || (r != 0 && s[0] == '1') || (l == 0) || (r == n-1)) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
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
