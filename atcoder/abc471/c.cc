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

  int current = 0;
  i64 ans = 0;
  multiset<int> pos(a.begin(), a.end());
  while (!pos.empty()) {
    auto it1 = pos.lower_bound(current);
    auto it2 = pos.upper_bound(current);

    if (it1 != pos.end() && it2 != pos.begin()) {
      --it2;
      int p1 = *it1;
      int p2 = *it2;
      int d1 = abs(current - p1);
      int d2 = abs(current - p2);
      if (d1 < d2) {
        ans += d1;
        current = p1;
        pos.erase(it1);
      } else {
        ans += d2;
        current = p2;
        pos.erase(it2);
      }
    } else if (it1 != pos.end()) {
      ans += abs(current - *it1);
      current = *it1;
      pos.erase(it1);
    } else if (it2 != pos.begin()) {
      --it2;
      ans += abs(current - *it2);
      current = *it2;
      pos.erase(it2);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
