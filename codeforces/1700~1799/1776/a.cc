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
  if (a[0] != 0) {
    a.insert(a.begin(), 0);
  }
  a.push_back(1440);

  int walk = 0;
  for (int i = 1; i < (int)a.size(); ++i) {
    int diff = a[i] - a[i-1];
    walk += diff / 120;
  }
  if (walk >= 2) {
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
