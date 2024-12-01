#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> ans(n+1);
  int x = 1;
  set<int> mods;
  for (int i = 1; i <= n; ++i) {
    while (mods.count(x % i)) {
      x++;
    }
    ans[i] = x;
    mods.insert(x % i);
    x++;
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
