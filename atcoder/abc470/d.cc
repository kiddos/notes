#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  vector<vector<int>> perm(2);
  perm[0] = p;
  perm[1] = vector<int>(n+1);
  for (int i = 0; i <= n; ++i) {
    perm[1][p[i]] = i;
  }

  int current = 0;
  for (int i = 0; i < q; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int x = 0, y = 0;
      cin >> x >> y;
      int px = perm[current][x], py = perm[current][y];
      swap(perm[current][x], perm[current][y]);
      swap(perm[current^1][px], perm[current^1][py]);
    } else if (t == 2) {
      current ^= 1;
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << perm[current][i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
