#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  pair<int,int> interval = {a[0], a[0]};
  for (int i = 1; i < n; ++i) {
    if (a[i] == interval.first - 1) {
      interval.first = a[i];
    } else if (a[i] == interval.second + 1) {
      interval.second = a[i];
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
