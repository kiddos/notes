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
  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && a[j]- a[i] <= 5) {
      j++;
    }
    int len = j - i;
    ans = max(ans, len);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
