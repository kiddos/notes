#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  map<int, int> prefix;
  prefix[0] = 1;
  int p = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int d = s[i] - '0';
    int offset = d-1;
    p += offset;
    ans += prefix[p];
    prefix[p]++;
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
