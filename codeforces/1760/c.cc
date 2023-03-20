#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n =0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> left(n), right(n);
    for (int i = 0; i < n; ++i) {
      left[i] = a[i];
      if (i > 0) left[i] = max(left[i], left[i-1]);
    }
    for (int i = n-1; i >= 0; --i) {
      right[i] = a[i];
      if (i < n-1) right[i] = max(right[i], right[i+1]);
    }

    for (int i = 0; i < n; ++i) {
      int max_val = max(i > 0 ? left[i-1] : 0, i+1 < n ? right[i+1] : 0);
      cout << a[i] - max_val << " ";
    }
    cout << endl;
  }
  return 0;
}
