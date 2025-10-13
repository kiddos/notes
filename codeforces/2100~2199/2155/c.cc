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

  auto possible = [&](char first) -> bool {
    string s(n, ' ');
    s[0] = first;
    for (int i = 1; i < n; ++i) {
      int diff = abs(a[i] - a[i-1]);
      if (diff > 1) {
        return false;
      }
      if (diff == 1) {
        s[i] = s[i-1] == 'R' ? 'R' : 'L';
      } else {
        s[i] = s[i-1] == 'R' ? 'L' : 'R';
      }
    }
    vector<int> left(n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L'){
        left[i]++;
      }
      if (i > 0) {
        left[i] += left[i-1];
      }
    }
    vector<int> right(n);
    for (int i = n-1; i >= 0; --i) {
      if (s[i] == 'R') {
        right[i]++;
      }
      if (i+1 < n) {
        right[i] += right[i+1];
      }
    }
    for (int i = 0; i < n; ++i) {
      int l = i > 0 ? left[i-1] : 0;
      int r = i+1 < n ? right[i+1] : 0;
      if (l + r != a[i] -1) {
        return false;
      }
    }
    return true;
  };

  int ans = 0;
  if (possible('L')) {
    ans++;
  }
  if (possible('R')) {
    ans++;
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
