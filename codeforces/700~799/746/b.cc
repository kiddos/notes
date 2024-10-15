#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string ans(n, ' ');
  int l = 0, r = n-1;
  for (int i = n-1, k = 0; i >= 0; --i, ++k) {
    if (k % 2 == 0) {
      ans[r--] = s[i];
    } else {
      ans[l++] = s[i];
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
