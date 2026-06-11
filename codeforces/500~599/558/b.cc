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
  map<int,vector<int>> indices;
  int max_freq = 0;
  for (int i = 0; i < n; ++i) {
    indices[a[i]].push_back(i);
    max_freq = max(max_freq, (int)indices[a[i]].size());
  }

  array<int,3> ans = {n, 1, n};
  for (auto [ai, index] : indices) {
    int size = index.size();
    if (size == max_freq) {
      int range = index.back() - index[0] + 1;
      ans = min(ans, {range, index[0]+1, index.back()+1});
    }
  }
  cout << ans[1] << " " << ans[2] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
