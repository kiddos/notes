#include <bits/stdc++.h>

using namespace std;

bool valid(vector<int>& a, int x) {
  int n = a.size();
  for (int i = 1; i < n; ++i) if (abs(a[i] - x) < abs(a[i-1]-x)) return false;
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

    bool inc = true, dec = true;
    for (int i = 1; i < n; ++i) {
      if (a[i] < a[i-1]) inc = false;
      if (a[i] > a[i-1]) dec = false;
    }

    if (inc) {
      int ans = *min_element(a.begin(), a.end());
      cout << ans << endl;
    } else if (dec) {
      int ans = *max_element(a.begin(), a.end());
      cout << ans << endl;
    } else {
      int min_val = 0, max_val = numeric_limits<int>::max();
      for (int i = 1; i < n; ++i) {
        int l = (a[i] + a[i-1]) / 2;
        int r = (a[i] + a[i-1] + 1) / 2;
        if (a[i] > a[i-1]) {
          max_val = min(max_val, l);
        }
        if (a[i] < a[i-1]) {
          min_val = max(min_val, r);
        }
      }
      if (max_val >= min_val) cout << min_val << endl;
      else cout << -1 << endl;
    }
  }
  return 0;
}
