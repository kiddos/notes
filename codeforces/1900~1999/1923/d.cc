#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+2);
  for (int i = 1; i <= n; ++i) cin >> a[i];
 
  vector<i64> p = a;
  for (int i = n-1; i >= 1; --i) p[i] += p[i+1];
  vector<int> count(n+2);
  for (int i = 1; i <= n; ++i) {
    count[i] = count[i-1];
    if (a[i] != a[i-1]) {
      count[i]++;
    }
  }

  vector<int> ans(n+1, numeric_limits<int>::max());
  for (int i = 2; i <= n; ++i) {
    int l = 1, r = i-1;
    // find the first j such that [j, i-1] has at least 2 different value
    int j = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (count[i-1]-count[mid] > 0) {
        j = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }

    // cout << "i=" << i << ",j=" << j << endl;

    // find the first j such that sum(a[j]...a[i-1]) > a[i]
    l = 1;
    r = j;
    j = -1;
    // cout << "i=" << i << endl;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      // cout << "sum=" << p[mid] - p[idx+1] << endl; 
      if (p[mid] - p[i] > a[i]) {
        j = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
 
    // cout << "j=" << j <<endl;
    if (j >= 0) {
      ans[i] = min(ans[i], i-j);
    }
    if (a[i-1] > a[i]) {
      ans[i] = min(ans[i], 1);
    }
  }
 
  p = a;
  for (int i = 2; i <= n; ++i) p[i] += p[i-1];
 
  for (int i = n-1; i >= 1; --i) {
    int l = i+1, r = n;
    int j = n+1;
    // find the first j such that [i+1, j] has at least 2 different value
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (count[mid] - count[i+1] > 0) {
        j = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }

    // cout << "i=" << i << ",j=" << j << endl;
    /// find the first j such that sum(a[i+1]...a[i]) > a[i]
    l = j;
    r = n;
    j = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (p[mid] - p[i] > a[i]) {
        j = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
 
    if (j >= 0) {
      ans[i] = min(ans[i], j-i);
    }
    if (a[i+1] > a[i]) {
      ans[i] = min(ans[i], 1);
    }
  }
 
  for (int i = 1; i <= n; ++i) {
    if (ans[i] == numeric_limits<int>::max()) {
      cout << "-1 ";
    } else {
      cout << ans[i] << " ";
    }
  }
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
