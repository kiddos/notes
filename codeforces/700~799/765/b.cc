#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<bool> found(26);
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    int c = s[i] -'a';
    if (found[c]) {
      continue;
    }
    for (int c2 = 0; c2 < c; ++c2) {
      if (!found[c2]) {
        cout << "NO" << endl;
        return;
      }
    }
    found[c] = true;
  }

  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
