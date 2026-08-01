#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int start = upper_bound(x.begin(), x.end(), b) - x.begin();
  int ans = 0;
  for (int i = start; i < n; ++i) {
    if (x[i] >= c) {
      break;
    }
    ans++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
