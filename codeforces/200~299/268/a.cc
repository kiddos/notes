#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> h(n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i] >> a[i];
  }
  vector<int> h_count(101);
  for (int i = 0; i < n; ++i) {
    h_count[h[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += h_count[a[i]];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
