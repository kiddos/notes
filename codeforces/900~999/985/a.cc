#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = n / 2;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  i64 ans1 = 0, ans2 = 0;
  for (int i = 0; i < m; ++i) {
    int even = i * 2 + 2;
    int odd = i * 2 + 1;
    ans1 += abs(even - a[i]);
    ans2 += abs(odd - a[i]);
  }
  i64 ans = min(ans1, ans2);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
