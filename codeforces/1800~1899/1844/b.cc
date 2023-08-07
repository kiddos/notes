#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  if (n == 1) {
    cout << "1" << endl;
    return;
  } else if (n == 2) {
    cout << "2 1" << endl;
    return;
  }

  vector<int> ans(n);
  ans[0] = 2;
  ans.back() = 3;
  ans[n/2] = 1;
  for (int i = 0, k = 4; i < n; ++i) if (!ans[i]) {
    ans[i] = k++;
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
