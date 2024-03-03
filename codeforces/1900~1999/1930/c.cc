#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  set<i64> not_used;
  set<i64> ans;
  for (int i = 1; i <= n; ++i) {
    i64 x = a[i] + i;
    if (ans.count(x)) {
      auto it = not_used.upper_bound(x);
      if (it != not_used.begin()) {
        it--;

        i64 x2 = *it;
        ans.insert(x2);

        not_used.erase(it);
        if (!ans.count(x2-1)) {
          not_used.insert(x2-1);
        }
      }
    } else {
      ans.insert(x);
      not_used.erase(x);

      if (!ans.count(x-1)) {
        not_used.insert(x-1);
      }
    }
  }

  for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
    cout << *it << " ";
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
