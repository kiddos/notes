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
  if (n % 2 == 1) {
    cout << "NO" << endl;
    return;
  }

  pair<int,int> possible = {numeric_limits<int>::min(), numeric_limits<int>::max()};
  for (int i = 0; i < n; i += 2) {
    int r = a[i], l = a[i+1];
    possible.first = max(possible.first, l+1);
    possible.second = min(possible.second, r-1);
    if (possible.first > possible.second) {
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
