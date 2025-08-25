#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int find_sqrt(int x) {
  i64 l = 1, r = x;
  int ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 sq = mid * mid;
    if (sq >= x) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  set<int> s = {n};
  int z = n;
  while (z > 2) {
    int sq = find_sqrt(z);
    s.insert(sq);
    z = sq;
  }

  vector<pair<int,int>> ans;
  for (int i = 2; i <= n; ++i) {
    if (!s.count(i)) {
      ans.emplace_back(i, n);
    }
  }

  vector<int> path(s.begin(), s.end());
  int p_size = path.size();
  for (int i = p_size-2; i >= 0; --i) {
    ans.emplace_back(path[i+1], path[i]);
    ans.emplace_back(path[i+1], path[i]);
  }

  cout << ans.size() << endl;
  for (auto [x, y] : ans) {
    cout << x << " " << y << endl;
  }
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
