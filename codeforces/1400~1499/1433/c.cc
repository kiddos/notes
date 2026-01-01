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
  int max_val = *max_element(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    if (a[i] == max_val) {
      if ((i-1 >= 0 && a[i-1] < max_val) || (i+1 < n && a[i+1] < max_val)) {
        cout << i+1 << endl;
        return;
      }
    }
  }
  cout << "-1" << endl;
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
