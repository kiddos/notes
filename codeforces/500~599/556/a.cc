#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> c(2);
  for (int i = 0; i < n; ++i) {
    c[s[i]-'0']++;
  }
  int remove = min(c[0], c[1]);
  int ans = n - remove * 2;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
