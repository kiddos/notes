#include <bits/stdc++.h>

using namespace std;

void solve() {
  int s = 0;
  cin >> s;
  string ans;
  int k = 9;
  while (s > 0) {
    int add = min(s, k);
    s -= add;
    ans.push_back(add + '0');
    k--;
  }
  reverse(ans.begin(), ans.end());
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
