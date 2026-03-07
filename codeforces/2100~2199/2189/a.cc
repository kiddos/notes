#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, h = 0, l = 0;
  cin >> n >> h >> l;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  multiset<int> s(a.begin(), a.end());
  if (l > h) {
    swap(l, h);
  }
  int ans = 0;
  while (s.size() >= 2) {
    auto it = s.upper_bound(h);
    if (it == s.begin()) {
      break;
    }
    --it;
    s.erase(it);

    it = s.upper_bound(l);
    if (it == s.begin()) {
      break;
    }
    --it;
    s.erase(it);

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
