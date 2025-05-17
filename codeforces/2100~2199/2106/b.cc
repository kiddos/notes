#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> p;
  for (int i = 0; i < x; ++i) {
    p.push_back(i);
  }
  for (int i = n-1; i >= x; --i) {
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
