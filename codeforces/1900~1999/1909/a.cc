#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> used(4);
  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    if (x < 0) {
      used[0] = 1;
    } else if (x > 0) {
      used[1] = 1;
    }

    if (y < 0) {
      used[2] = 1;
    } else if (y > 0) {
      used[3] = 1;
    }
  }

  int total = accumulate(used.begin(), used.end(), 0);
  if (total <= 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
