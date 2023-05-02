#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& a) {
  int last_even = 0, last_odd = 0;
  bool e = false, o = false;
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      if (e) {
        if (a[i] < last_even) return false;
      } else {
        e = true;
      }
      last_even = a[i];
    } else {
      if (o) {
        if (a[i] < last_odd) return false;
      } else {
        o = true;
      }
      last_odd = a[i];
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool ans = solve(a);
    if (ans) cout << "Yes\n";
    else cout << "No\n";
  }
  cout << flush;
  return 0;
}
