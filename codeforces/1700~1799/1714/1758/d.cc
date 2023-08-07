#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  if (n == 2) {
    cout << "1 3" << endl;
    return;
  }

  int s = n;
  int rest = (1 + (n-2)) * (n-2) / 2;
  // a_last - a1 = s
  // a_last * 2 = s ^ 2 + s - rest
  int a_last = (s * s + s - rest) / 2;
  int a1 = a_last - s;
  vector<int> ans = {a1, a_last};
  for (int i = 2, k = 1; i < n; ++i, ++k) {
    ans.push_back(k);
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
