#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;

  int n = s.length(), m = t.length();
  vector<int> prefix(n);
  int ans = 0;
  for (int i = 0, j = 0, matched = 0; i < n; ++i) {
    if (j < m && t[j] == s[i]) {
      matched++;
      j++;
    }
    prefix[i] = matched;

    if (matched == m) {
      ans = max(ans, n-i-1);
    }
  }

  vector<int> suffix(n+1);
  for (int i = n-1, j = m-1, matched = 0; i >= 0; --i) {
    if (j >= 0 && t[j] == s[i]) {
      matched++;
      j--;
    }
    suffix[i] = matched;

    if (matched == m) {
      ans = max(ans, i);
    }
  }

  for (int i = 0; i < n; ++i) {
    int need = m - prefix[i];
    int l = i+1, r = n-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (suffix[mid] >= need) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    if (idx >= 0) {
      int len = idx - i -1;
      ans = max(ans, len);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
