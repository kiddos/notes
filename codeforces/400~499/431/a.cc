#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> a(5);
  for (int i = 1; i <= 4; ++i) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  int ans = 0;
  for (char ch : s) {
    int c = ch - '0';
    ans += a[c];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
