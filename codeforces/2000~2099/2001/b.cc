#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n % 2 == 0) {
    cout << "-1" << endl;
    return;
  }

  vector<int> ans;
  for (int i = n; i >= 1; i -= 2) {
    ans.push_back(i);
  }
  for (int i = 2; i < n; i += 2) {
    ans.push_back(i);
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
