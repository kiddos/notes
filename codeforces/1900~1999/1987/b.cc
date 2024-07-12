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

  vector<int> b = a;
  for (int i = 1; i < n; ++i) {
    b[i] = max(b[i], b[i-1]);
  }

  multiset<int> adds;
  for (int i = 0; i < n; ++i) {
    i64 add = b[i] - a[i];
    if (add) {
      adds.insert(add);
    }
  }

  i64 ans = 0;
  i64 added = 0;
  while (!adds.empty()) {
    i64 to_add = *adds.begin() - added;
    i64 k = adds.size();
    ans += to_add * (k+1);
    adds.erase(adds.begin());
    added += to_add;
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
