#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, v = 0;
  cin >> n >> m >> v;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }

  vector<int> prefix(n);
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    if (sum >= v) {
      prefix[i]++;
      sum = 0;
    }
    if (i > 0) {
      prefix[i] += prefix[i-1];
    }
  }

  i64 ans = -1;
  for (int i = 0; i < n; ++i) {
    if (prefix[i] >= m) {
      ans = max(ans, p[n] - p[i+1]);
    }
  }

  vector<int> suffix(n);
  sum = 0;
  for (int i = n-1; i >= 0; --i) {
    sum += a[i];
    if (sum >= v) {
      suffix[i]++;
      sum = 0;
    }
    if (i+1 < n) {
      suffix[i] += suffix[i+1];
    }
  }

  for (int i = n-1; i >= 0; --i) {
    if (suffix[i] >= m) {
      ans = max(ans, p[i]);
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << prefix[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << suffix[i] << " ";
  // }
  // cout << endl;

  for (int i = 0; i < n; ++i) {
    int pre = i-1 >= 0 ? prefix[i-1] : 0;
    int l = i, r = n-1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 suf = mid+1 < n ? suffix[mid+1] : 0;
      if (suf + pre >= m) {
        ans = max(ans, p[mid+1] - p[i]);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
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
