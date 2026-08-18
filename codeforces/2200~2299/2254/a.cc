#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  vector<int> vals = {a, b, c};
  sort(vals.begin(), vals.end());
  int ans = 0;
  while (vals[0] != vals[1] && vals[0] != vals[2] && vals[1] != vals[2]) {
    vals[2]--;
    vals[0]++;
    ans++;
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
