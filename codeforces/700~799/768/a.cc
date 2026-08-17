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
  int max_val = *max_element(a.begin(), a.end());
  int min_val = *min_element(a.begin(), a.end());
  int ans =0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > min_val && a[i] < max_val) {
      ans++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
