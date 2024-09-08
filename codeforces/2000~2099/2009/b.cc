#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> rows(n);
  for (int i = 0; i < n; ++i) {
    cin >> rows[i];
  }
  for (int i = n-1; i >= 0; --i) {
    int idx = find(rows[i].begin(), rows[i].end(), '#') - rows[i].begin();
    cout << idx+1 << " ";
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
