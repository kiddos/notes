#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<int> a = {b[0]};
  for (int i = 1; i < n; ++i) {
    if (b[i] < a.back()) {
      a.push_back(b[i]);
    }
    a.push_back(b[i]);
  }
  cout << a.size() << endl;
  for (int x : a) cout << x << " ";
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
