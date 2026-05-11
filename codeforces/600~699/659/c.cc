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
  sort(a.begin(), a.end());
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }

  i64 l = 0, r = 1000000000;
  i64 pick = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 total_cost = (mid + 1) * mid / 2;
    auto it = upper_bound(a.begin(), a.end(), mid);
    i64 already_has = it - a.begin();
    i64 spend = total_cost - p[already_has];
    if (spend <= m) {
      l = mid+1;
      pick = mid;
    } else {
      r = mid-1;
    }
  }

  vector<int> ans;
  set<int> s(a.begin(), a.end());
  for (int i = 1; i <= pick; ++i) {
    if (!s.count(i)) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int idx : ans) {
    cout << idx << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
