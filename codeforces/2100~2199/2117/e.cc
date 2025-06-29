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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  set<int> s1, s2, s3, s4;
  int idx = -1;
  for (int i = n-1; i >= 0; --i) {
    if (a[i] == b[i]) {
      idx = i;
      break;
    }

    if (i % 2 == 0) {
      if (s1.count(b[i]) || s2.count(a[i])) {
        idx = i;
        break;
      }
      s1.insert(a[i]);
      s2.insert(b[i]);

      // if remove i+1
      if (s3.count(a[i]) || s4.count(b[i])) {
        idx = i;
        break;
      }
      if (i+1 < n) {
        s3.insert(b[i+1]);
        s4.insert(a[i+1]);
      }
    } else {
      if (s1.count(a[i]) || s2.count(b[i])) {
        idx = i;
        break;
      }
      s1.insert(b[i]);
      s2.insert(a[i]);

      // if remove i+1
      if (s3.count(b[i]) || s4.count(a[i])) {
        idx = i;
        break;
      }
      if (i+1 < n) {
        s3.insert(a[i+1]);
        s4.insert(b[i+1]);
      }
    }
  }
  
  int ans = idx+1;
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
