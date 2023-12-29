#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  auto possible = [&](i64 k) -> bool {
    set<i64> mod;
    for (int i = 0; i < n; ++i) {
      mod.insert(a[i] % k);
    }
    return mod.size() == 2;
  };

  i64 k = 2;
  while (!possible(k)) {
    k *= 2;
  }

  cout << k << endl;
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
