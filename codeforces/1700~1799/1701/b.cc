#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> ans;

  vector<bool> used(n+1);
  for (int i = 1; i <= n; ++i) if (!used[i]) {
    int p = i;
    while (p <= n) {
      used[p] = true;
      ans.push_back(p);
      p <<= 1;
    }
  }

  // cout << "size=" << ans.size() << endl;
  cout << "2" << endl;
  for (int p : ans) cout << p << " ";
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
