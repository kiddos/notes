#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> ans(n+1);
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i += 2) {
      ans[i] = i+1;
      ans[i+1] = i;
    }
  } else {
    ans[1] = 3;
    ans[2] = 1;
    ans[3] = 2;
    for (int i = 4; i <= n; i += 2) {
      ans[i] = i+1;
      ans[i+1] = i;
    }
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
