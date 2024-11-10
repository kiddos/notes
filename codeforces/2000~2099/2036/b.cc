#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> b(k), c(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i] >> c[i];
  }

  map<int, int> total;
  for (int i = 0; i < k; ++i) {
    total[b[i]] += c[i];
  }
  vector<pair<int,int>> bottles(total.begin(), total.end());
  sort(bottles.begin(), bottles.end(), [&](auto& b1, auto& b2) {
    return b1.second > b2.second;
  });
  int size = bottles.size();
  int ans = 0;
  for (int i = 0; i < min(size, n); ++i) {
    ans += bottles[i].second;
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
