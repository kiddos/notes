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
  vector<int> decreasing;
  vector<int> ans(n, -1);
  for (int i = n-1; i >= 0; --i) {
    int size = decreasing.size();
    int l = 0, r = size-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (a[decreasing[mid]] < a[i]) {
        idx = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }

    if (idx >= 0) {
      int dist = decreasing[idx] - i-1;
      ans[i] = dist;
    }

    if (decreasing.empty() || a[decreasing.back()] > a[i]) {
      decreasing.push_back(i);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
