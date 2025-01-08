#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string ans;
  for (int i = 0; i < n/2; ++i) {
    ans.push_back('a');
  }
  ans.push_back('b');
  if (n % 2 == 1 && (int)ans.length() < n) {
    ans.push_back('c');
  }
  while ((int)ans.length() < n) {
    ans.push_back('a');
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
