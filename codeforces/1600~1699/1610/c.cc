#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> friends;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    friends.emplace_back(a, b);
  }

  auto possible = [&](int k) -> bool {
    int add = 0;
    for (int i = 0; i < n; ++i) {
      int poor = add, richer = k-add-1;
      if (friends[i].second >= poor && friends[i].first >= richer) {
        add++;
      }
    }
    return add >= k;
  };

  int l = 1, r = n;
  int ans = 1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
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
