#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum class UpdateType { Assign, Add };

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int left = 0;
    for (int j = 1; j < i; ++j) {
      left += p[j] > p[i];
    }
    int right = 0;
    for (int j = i+1; j <= n; ++j) {
      right += p[j] > p[i];
    }
    ans += min(left, right);
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
