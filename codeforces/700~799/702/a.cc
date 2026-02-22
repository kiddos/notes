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
  int i = 0;
  int ans = 0;
  while (i < n) {
    int j = i;
    while (j+1 < n && a[j+1] > a[j]) {
      j++;
    }
    int len = j-i+1;
    ans = max(ans, len);
    i = j+1;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
