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
  for (int i = 0; i < n; ++i) {
    indices[a[i]].push_back(i);
  }
  int ans = n;
  for (auto [val, index] : indices) {
    int last = -1;
    int remove = 0;
    for (int idx : index) {
      if (idx != last + 1) {
        remove++;
      }
      last = idx;
    }
    if (n != last+1) {
      remove++;
    }
    ans = min(ans, remove);
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
