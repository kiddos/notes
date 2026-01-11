#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  string last;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != last) {
      ans++;
    }
    last = s[i];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
