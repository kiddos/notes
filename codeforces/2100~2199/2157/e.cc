#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = 2 * n;
  vector<int> count(m+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  bool found = false;
  for (int i = 1; i <= m; ++i) {
    if (count[i] > k) {
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "0" << endl;
    return;
  }

  int i = 1;
  int ans = 0;
  while (i <= m) {
    if (count[i] <= 1) {
      i++;
    } else {
      int to_increase = 0;
      int j = i;
      while (j <= m && to_increase + count[j] > k) {
        if (count[j] > 1) {
          to_increase += count[j] - 1;
        } else if (count[j] == 0) {
          to_increase--;
        }
        j++;
      }

      int step = j-i;
      // cout << "j=" << j << ",i=" << i << ", to increase=" << to_increase << endl;
      if (to_increase > k) {
        step += to_increase - k;
      }
      ans = max(ans, step);
      i = j+1;
    }
  }
  cout << ans << endl;
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
