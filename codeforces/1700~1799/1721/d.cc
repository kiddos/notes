#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  auto possible = [&](int k) -> bool {
    map<int, int> count;
    for (int i = 0; i < n; ++i) {
      count[k & a[i]]++;
      count[k & (~b[i])]--;
    }

    for (auto& [bits, c] : count) {
      if (c != 0) return false;
    }
    return true;
  };

  int ans = 0;
  for (int bit = 30; bit >= 0; --bit) {
    if (possible(ans | (1<<bit))) {
      ans |= (1<<bit);
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
