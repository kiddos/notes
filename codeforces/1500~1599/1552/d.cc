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

  function<bool(int,int,int,int)> backtrack = [&](int i, int ignore, int sum, int target) -> bool {
    if (i == n) {
      return sum == target;
    }
    if (i == ignore) return backtrack(i+1, ignore, sum, target);
    return backtrack(i+1, ignore, sum, target) ||
      backtrack(i+1, ignore, sum + a[i], target) ||
      backtrack(i+1, ignore, sum - a[i], target);
  };

  for (int i = 0; i < n; ++i) {
    if (backtrack(0, i, 0, a[i])) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
