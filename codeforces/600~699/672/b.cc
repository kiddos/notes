#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  if (n > 26) {
    cout << "-1" << endl;
    return;
  }
  vector<bool> found(26);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    if (found[c]) {
      ans++;
    } else {
      found[c] = true;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
