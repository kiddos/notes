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
  int x = a.back();
  i64 ans = x;
  for (int i = n-2; i >= 0; --i) {
    int buy = min(a[i], max(x-1, 0));
    ans += buy;
    x = buy;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
