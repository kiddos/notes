#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int u, int v) {
  cout << u << " " << v << endl;
  int result = 0;
  cin >> result;
  return result;
}

void solve() {
  int n = 0;
  cin >> n;

  vector<int> batteries(n);
  iota(batteries.begin(), batteries.end(), 1);

  for (int d = 1; d <= n; ++d) {
    for (int i = 0; i < n; ++i) {
      int b1 = batteries[i];
      int b2 = batteries[(i+d)%n];
      int result = query(b1, b2);
      if (result) {
        return;
      }
    }
  }
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
