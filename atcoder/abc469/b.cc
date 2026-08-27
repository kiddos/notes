#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string s2 = "x" + s + "x";
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (s2[i-1] == 'x' && s2[i+1] == 'x' && s2[i] == 'x') {
      ans++;
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
