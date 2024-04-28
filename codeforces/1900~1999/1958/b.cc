#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  int b = 30;
  vector<int> ans;
  int size = n;
  while (size > 1) {
    while ((1<<b) - 1 > k) {
      b--;
    }
    int x = (1<<b) -1;
    k -= x;
    ans.push_back(x);
    size--;
  }
  ans.push_back(k);
  while ((int)ans.size() < n) {
    ans.push_back(0);
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
