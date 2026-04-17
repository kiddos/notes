#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = n * 2;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<int> ans;
  vector<bool> found(n+1);
  for (int i = 0; i < m; ++i) {
    if (!found[a[i]]) {
      ans.push_back(a[i]);
    }
    found[a[i]] = true;
  }

  for (int ai : ans) {
    cout << ai << " ";
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
