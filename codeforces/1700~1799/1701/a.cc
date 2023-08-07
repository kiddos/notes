#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<int> grid(4);
  for (int i = 0; i < 4; ++i) cin >> grid[i];

  int sum = accumulate(grid.begin(), grid.end(), 0);
  if (sum == 4) {
    cout << "2" << endl;
  } else if (sum > 0) {
    cout << "1" << endl;
  } else {
    cout << "0" << endl;
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
