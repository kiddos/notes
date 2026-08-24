#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> l(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  int total = accumulate(l.begin(), l.end(), 0);
  int left = 0;
  int right = total;
  int ans = total;
  for (int i = 0; i < n-1; ++i) {
    left += l[i];
    right -= l[i];
    ans = min(ans, abs(left - right));
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
