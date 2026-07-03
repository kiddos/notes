#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  k = min(k, n);
  // x + y = k
  // 2*x + y = n
  // x = n - k
  int x = n - k;
  int y = k - x;
  sort(s.begin(), s.end());
  int l = 0, r = n-y-1;
  int ans = 0;
  while (l < r) {
    int sum = s[l] + s[r];
    k++;
    l++;
    r--;
    ans = max(ans, sum);
  }
  for (int i = n-y; i < n; ++i) {
    ans = max(ans, s[i]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
