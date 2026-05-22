#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, d = 0;
  cin >> n >> d;
  vector<int> m(n), s(n);
  for (int i = 0; i < n; ++i) {
    cin >> m[i] >> s[i];
  }
  vector<pair<i64,i64>> friends;
  for (int i = 0; i < n; ++i) {
    friends.push_back({m[i], s[i]});
  }
  sort(friends.begin(), friends.end());
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + friends[i].second);
  }
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n-1;
    int idx = l;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (friends[mid].first - friends[i].first < d) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    i64 total = p[idx+1] - p[i];
    ans = max(ans, total);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
