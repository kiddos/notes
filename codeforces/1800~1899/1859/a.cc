#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int max_val = *max_element(a.begin(), a.end());
  vector<int> b, c;
  for (int i = 0; i < n; ++i) {
    if (a[i] == max_val) {
      c.push_back(a[i]);
    } else {
      b.push_back(a[i]);
    }
  }

  if (c.size() == n) {
    cout << "-1" << endl;
    return;
  }

  cout << b.size() << " " << c.size() << endl;
  for (int x : b) cout << x << " ";
  cout << endl;
  for (int x : c) cout << x << " ";
  cout << endl;
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
