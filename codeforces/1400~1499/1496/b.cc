#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  set<int> exclude, include;
  for (int i = 0; i <= 2 * n; ++i) {
    exclude.insert(i);
  }
  for (int i = 0; i < n; ++i) {
    exclude.erase(a[i]);
    include.insert(a[i]);
  }

  while (k-- > 0) {
    int mex = *exclude.begin();
    int max_val = *include.rbegin();
    int to_add = (mex + max_val + 1) / 2;
    if (include.count(to_add)) {
      cout << include.size() << endl;
      return;
    } else if (to_add > max_val) {
      include.insert(to_add);
      cout << include.size() + k << endl;
      return;
    } else {
      include.insert(to_add);
      exclude.erase(to_add);
    }
  }
  cout << include.size() << endl;
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
