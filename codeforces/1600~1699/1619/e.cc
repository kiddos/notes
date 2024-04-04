#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> counts(n+1);
  vector<i64> closest(n+1, -1);
  multiset<int> s;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0 && a[i] <= n) {
      counts[a[i]]++;

      if (closest[a[i]] < 0) {
        closest[a[i]] = 0;
      } else {
        s.insert(a[i]);
      }
    }
  }

  for (int i = 0; i <= n; ++i) {
    if (closest[i] < 0) {
      auto it = s.upper_bound(i);
      if (it != s.begin()) {
        --it;
        closest[i] = i - *it;
        s.erase(it);
      }
    }
  }


  vector<i64> ans(n+1, -1);
  for (int i = 0; i <= n; ++i) {
    if (i == 0) {
      ans[i] = counts[i];
    } else {
      if (ans[i-1] >= 0 && closest[i-1] >= 0) {
        ans[i] = ans[i-1] - counts[i-1] + counts[i] + closest[i-1];
      }
    }
  }

  for (int i = 0; i <= n; ++i) {
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
