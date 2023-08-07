#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  map<int, int> counts;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    counts[a]++;
  }

  int remove = 0;
  for (auto& [a, count] : counts) {
    if (count > 1) {
      remove += count - 1;
    }
  }

  int ops = (remove+1) / 2;
  int ans = n - ops * 2;
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
