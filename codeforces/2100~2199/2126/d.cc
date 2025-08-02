#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> l(n), r(n), real(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i] >> real[i];
  }
  map<int,int> can_get_to;
  for (int i = 0; i < n; ++i) {
    can_get_to[l[i]] = max(can_get_to[l[i]], real[i]);
  }
  auto it = can_get_to.begin();
  int current = k;
  while (it != can_get_to.end() && it->first <= current) {
    current = max(current, it->second);
    it = next(it);
  }
  cout << current << endl;
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
