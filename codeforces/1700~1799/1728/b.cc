#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> ans(n);
  if (n % 2 == 1) {
    ans[n-1] = n;
    ans[n-2] = n-2;
    ans[n-3] = 1;
    for (int i = n-4, k = 1; i >= 0; --i) {
      while (k == 1 || k == n-2 || k == n) k++;
      ans[i] = k++;
    }
  } else {
    ans[n-1] = n;
    ans[n-2] = n-1;
    for (int i = n-3, k = 1; i >= 0; --i) {
      ans[i] = k++;
    }
  }

  for (int i = 0; i < n; ++i) {
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
