#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> ans = {1, 3};
  int current = 4;
  while ((int) ans.size() < n) {
    int size = ans.size();
    i64 x = ans[size-1];
    i64 y = ans[size-2];
    while ((current * 3) % (x+y) == 0) {
      current++;
    }
    ans.push_back(current++);
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
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
