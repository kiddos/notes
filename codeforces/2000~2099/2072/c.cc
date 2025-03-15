#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  int y = 0;
  vector<int> ans;
  int mask = ~x;
  for (int i = 0; i < n; ++i) {
    if (!(i & mask)) {
      y |= i;
      ans.push_back(i);
    }
  }
  if (y != x) {
    if ((int)ans.size() < n) {
      ans.push_back(x);
    } else {
      ans.back() = x;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i % ans.size()] << " ";
  }
  cout << endl;
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
