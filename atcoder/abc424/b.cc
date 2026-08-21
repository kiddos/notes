#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(k), b(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i] >> b[i];
  }
  vector<vector<int>> solved(n+1);
  vector<int> ans;
  for (int i = 0; i < k; ++i) {
    solved[a[i]].push_back(b[i]);
    if ((int)solved[a[i]].size() == m) {
      ans.push_back(a[i]);
    }
  }

  for (int p : ans) {
    cout << p << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
