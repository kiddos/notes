#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  multiset<int> s(a.begin(), a.end());
  int last = *s.rbegin();
  s.erase(s.find(last));
  i64 ans = last;
  while (!s.empty()) {
    auto it = s.upper_bound(m-last);
    if (it == s.begin()) {
      last = *s.rbegin();
      ans += last + 1;
      s.erase(s.find(last));
    } else {
      --it;
      last = *it;
      ans += last;
      s.erase(it);
    }
  }
  ans++;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
