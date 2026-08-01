#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> total(2), reached(2);
  for (int i = 0; i < n; ++i) {
    int t = 0, x = 0, y = 0;
    cin >> t >> x >> y;
    t--;
    total[t] += 10;
    reached[t] += x;
  }

  for (int t = 0; t < 2; ++t) {
    if (reached[t] * 2 >= total[t]) {
      cout << "LIVE" << endl;
    } else {
      cout << "DEAD" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
