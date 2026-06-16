#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n), d(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> d[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (x[i] + d[i] == x[j] && x[j] + d[j] == x[i]) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
