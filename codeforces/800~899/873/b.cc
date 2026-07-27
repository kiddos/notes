#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  map<int,int> p;
  p[0] = -1;
  int ans = 0;
  for (int i = 0, b = 0; i < n; ++i) {
    if (s[i] == '1') {
      b++;
    } else if (s[i] == '0') {
      b--;
    }

    if (p.count(b)) {
      ans = max(ans, i - p[b]);
    } else {
      p[b] = i;
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
