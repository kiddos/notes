#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<int> suffix(n);
  for (int i = n-1, j = m-1; i >= 0; --i) {
    if (j >= 0 && s[i] == t[j]) {
      j--;
    }
    suffix[i] = m-j-1;
  }

  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    if (s[i] == t[j]) {
      j++;
    }
    if (j >= m) {
      break;
    }

    if (j > 0 && j < m) {
      int left = m-j;
      int l = i+1, r = n-1;
      int idx =r;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        if (suffix[mid] >= left) {
          l = mid+1;
          idx = mid;
        } else {
          r = mid-1;
        }
      }
      ans = max(ans, idx-i);
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
