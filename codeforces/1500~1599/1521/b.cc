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
  int min_index = min_element(a.begin(), a.end()) - a.begin();
  int min_val = a[min_index];
  vector<array<int,4>> ans;
  for (int i = 0; i < n; ++i) {
    if (i == min_index) continue;
    int dist = abs(i - min_index);
    if (i < min_index) {
      ans.push_back({i, min_index, min_val + dist, min_val});
    } else {
      ans.push_back({min_index, i, min_val, min_val + dist});
    }
  }

  cout << ans.size() << endl;
  for (auto [i, j, x, y] : ans) {
    cout << i+1 << " " << j+1 << " " << x << " " << y << endl;
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
