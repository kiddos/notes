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
  vector<int> p = {n};
  for (int i = 1; i < n; ++i) {
    p.push_back(i);
  }
  for (int pi : p) {
    cout << pi << " ";
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
