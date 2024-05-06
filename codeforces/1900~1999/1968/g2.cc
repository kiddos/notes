#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> z_function(const string& s) {
  int n = s.length();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i < r) {
      z[i] = min(r-i, z[i-l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i+z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

void solve() {
  int n = 0, l = 0, r = 0;
  cin >> n >> l >> r;
  string s;
  cin >> s;

  vector<int> z = z_function(s);

  auto possible = [&](int k, int len) -> bool {
    int count = 1;
    for (int i = len; i < n;) {
      if (z[i] >= len) {
        count++;
        i += len;
      } else {
        i++;
      }
    }
    return count >= k;
  };

  auto find_max_len = [&](int k) -> int {
    int l = 1, r = n/k;
    int ans = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (possible(k, mid)) {
        ans = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  int m = sqrt(n);
  vector<int> ans(n+1);
  for (int k = 1; k <= m; ++k) {
    ans[k] = find_max_len(k);
  }

  // for (int i = 0; i < n; ++i) cout << z[i] << " ";
  // cout << endl;

  for (int len = 1; len <= m; ++len) {
    int k = 1;
    for (int i = len; i < n;) {
      if (z[i] >= len) {
        k++;
        i += len;
      } else {
        i++;
      }
    }
    ans[k] = max(ans[k], len);
  }

  for (int i = n-1; i >= 1; --i) {
    ans[i] = max(ans[i], ans[i+1]);
  }

  for (int i = l; i <= r; ++i) {
    cout << ans[i] << " ";
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
