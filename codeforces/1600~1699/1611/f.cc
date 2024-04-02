#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 s = 0;
  cin >> n >> s;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<i64> p(n);
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    p[i] = sum;
  }
  for (int i = 1; i < n; ++i) {
    p[i] = min(p[i], p[i-1]);
  }

  i64 prefix = 0;
  int len = -1;
  pair<int,int> ans;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (s + p[mid] - prefix >= 0) {
        idx = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }

    if (idx >= 0) {
      int new_len = idx - i + 1;
      if (new_len > len) {
        len = new_len;
        ans = {i+1, idx+1};
      }
    }
    prefix += a[i];
  }

  if (len >= 0) {
    cout << ans.first << " " << ans.second << endl;
  } else {
    cout << "-1" << endl;
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
