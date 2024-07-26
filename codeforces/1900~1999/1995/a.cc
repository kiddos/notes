#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> sizes = {0, n};
  for (int size = n-1; size >= 1; --size) {
    sizes.push_back(size);
    sizes.push_back(size);
  }
  for (int i = 0; i < (int) sizes.size(); ++i) {
    if (i > 0) {
      sizes[i] += sizes[i-1];
    }
    if (sizes[i] >= k) {
      cout << i << endl;
      return;
    }
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
