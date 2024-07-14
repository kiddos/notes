#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 1;
  set<int> s;
  if (x % a[0] == 0) {
    s.insert(a[0]);
  }

  for (int i = 1; i < n; ++i) {
    if (x % a[i] == 0 && s.count(x / a[i])) {
      s.clear();
      s.insert(a[i]);
      ans++;
    } else {
      if (a[i] > 1 && x % a[i] == 0) {
        set<int> s2 = s;
        for (int p : s) {
          if (x % (p * a[i]) == 0) {
            s2.insert(p * a[i]);
          }
        }
        s2.insert(a[i]);
        s = std::move(s2);
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
