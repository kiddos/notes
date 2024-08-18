#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  map<int, int> points;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    points[a]++;
  }

  if (points.size() == 1) {
    cout << "YES" << endl;
  } else if (points.size() == 2) {
    int p1 = points.begin()->first;
    int p2 = points.rbegin()->first;
    if (p2 - p1 > 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
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
