#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  
  vector<int> possible;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int base = x[j] - x[i];
      possible.push_back(base);
    }
  }
  sort(possible.begin(), possible.end());
  possible.resize(unique(possible.begin(), possible.end()) - possible.begin());
  int ans = possible.size();
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
