#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, r = n-1;
  while (l < n && s[l] == 'W') l++;
  while (r >= 0 && s[r] == 'W') r--;
  int len = max(r-l+1, 0);
  cout << len << endl;
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
