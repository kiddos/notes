#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0;
  cin >> x;
  vector<int> divs;
  for (int d = 1; d * d <= x; ++d) {
    if (x % d == 0) {
      divs.push_back(d);
      divs.push_back(x / d);
    }
  }
  sort(divs.begin(), divs.end());
  divs.resize(unique(divs.begin(), divs.end()) - divs.begin());
  cout << divs.size() << endl;
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
